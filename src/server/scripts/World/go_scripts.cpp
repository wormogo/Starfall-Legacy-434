/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ContentData
go_cat_figurine (the "trap" version of GO, two different exist)
go_northern_crystal_pylon
go_eastern_crystal_pylon
go_western_crystal_pylon
go_barov_journal
go_ethereum_prison
go_ethereum_stasis
go_sacred_fire_of_life
go_shrine_of_the_birds
go_southfury_moonstone
go_field_repair_bot_74A
go_orb_of_command
go_resonite_cask
go_tablet_of_madness
go_tablet_of_the_seven
go_tele_to_dalaran_crystal
go_tele_to_violet_stand
go_scourge_cage
go_jotunheim_cage
go_table_theka
go_soulwell
go_bashir_crystalforge
go_ethereal_teleport_pad
go_soulwell
go_dragonflayer_cage
go_tadpole_cage
go_amberpine_outhouse
go_hive_pod
go_gjalerbron_cage
go_large_gjalerbron_cage
go_veil_skith_cage
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameObjectAI.h"
#include "Spell.h"
#include "Player.h"
#include "WorldSession.h"

/*######
## go_cat_figurine
######*/

enum CatFigurine
{
    SPELL_SUMMON_GHOST_SABER    = 5968,
};

class go_cat_figurine : public GameObjectScript
{
public:
    go_cat_figurine() : GameObjectScript("go_cat_figurine") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        player->CastSpell(player, SPELL_SUMMON_GHOST_SABER, true);
        return false;
    }
};

/*######
## go_crystal_pylons (3x)
######*/
class go_northern_crystal_pylon : public GameObjectScript
{
public:
    go_northern_crystal_pylon() : GameObjectScript("go_northern_crystal_pylon") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
        {
            player->PrepareQuestMenu(go->GetGUID());
            player->SendPreparedQuest(go->GetGUID());
        }

        if (player->GetQuestStatus(4285) == QUEST_STATUS_INCOMPLETE)
            player->AreaExploredOrEventHappens(4285);

        return true;
    }
};

class go_eastern_crystal_pylon : public GameObjectScript
{
public:
    go_eastern_crystal_pylon() : GameObjectScript("go_eastern_crystal_pylon") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
        {
            player->PrepareQuestMenu(go->GetGUID());
            player->SendPreparedQuest(go->GetGUID());
        }

        if (player->GetQuestStatus(4287) == QUEST_STATUS_INCOMPLETE)
            player->AreaExploredOrEventHappens(4287);

        return true;
    }
};

class go_western_crystal_pylon : public GameObjectScript
{
public:
    go_western_crystal_pylon() : GameObjectScript("go_western_crystal_pylon") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
        {
            player->PrepareQuestMenu(go->GetGUID());
            player->SendPreparedQuest(go->GetGUID());
        }

        if (player->GetQuestStatus(4288) == QUEST_STATUS_INCOMPLETE)
            player->AreaExploredOrEventHappens(4288);

        return true;
    }
};

/*######
## go_barov_journal
######*/

class go_barov_journal : public GameObjectScript
{
public:
    go_barov_journal() : GameObjectScript("go_barov_journal") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->HasSkill(SKILL_TAILORING) && player->GetBaseSkillValue(SKILL_TAILORING) >= 280 && !player->HasSpell(26086))
            player->CastSpell(player, 26095, false);

        return true;
    }
};

/*######
## go_field_repair_bot_74A
######*/

class go_field_repair_bot_74A : public GameObjectScript
{
public:
    go_field_repair_bot_74A() : GameObjectScript("go_field_repair_bot_74A") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->HasSkill(SKILL_ENGINEERING) && player->GetBaseSkillValue(SKILL_ENGINEERING) >= 300 && !player->HasSpell(22704))
            player->CastSpell(player, 22864, false);

        return true;
    }
};

/*######
## go_gilded_brazier (Paladin First Trail quest (9678))
######*/

enum GildedBrazier
{
    NPC_STILLBLADE  = 17716,
};

class go_gilded_brazier : public GameObjectScript
{
public:
    go_gilded_brazier() : GameObjectScript("go_gilded_brazier") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
        {
            if (player->GetQuestStatus(9678) == QUEST_STATUS_INCOMPLETE)
            {
                if (Creature* Stillblade = player->SummonCreature(NPC_STILLBLADE, 8106.11f, -7542.06f, 151.775f, 3.02598f, TEMPSUMMON_DEAD_DESPAWN, 60000))
                    Stillblade->AI()->AttackStart(player);
            }
        }
        return true;
    }
};

/*######
## go_orb_of_command
######*/

class go_orb_of_command : public GameObjectScript
{
public:
    go_orb_of_command() : GameObjectScript("go_orb_of_command") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->GetQuestRewardStatus(7761))
            player->CastSpell(player, 23460, true);

        return true;
    }
};

/*######
## go_tablet_of_madness
######*/

class go_tablet_of_madness : public GameObjectScript
{
public:
    go_tablet_of_madness() : GameObjectScript("go_tablet_of_madness") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->HasSkill(SKILL_ALCHEMY) && player->GetSkillValue(SKILL_ALCHEMY) >= 300 && !player->HasSpell(24266))
            player->CastSpell(player, 24267, false);

        return true;
    }
};

/*######
## go_tablet_of_the_seven
######*/

class go_tablet_of_the_seven : public GameObjectScript
{
public:
    go_tablet_of_the_seven() : GameObjectScript("go_tablet_of_the_seven") { }

    //TODO: use gossip option ("Transcript the Tablet") instead, if Trinity adds support.
    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER)
            return true;

        if (player->GetQuestStatus(4296) == QUEST_STATUS_INCOMPLETE)
            player->CastSpell(player, 15065, false);

        return true;
    }
};

/*#####
## go_jump_a_tron
######*/

class go_jump_a_tron : public GameObjectScript
{
public:
    go_jump_a_tron() : GameObjectScript("go_jump_a_tron") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->GetQuestStatus(10111) == QUEST_STATUS_INCOMPLETE)
            player->CastSpell(player, 33382, true);

        return true;
    }
};

/*######
## go_ethereum_prison
######*/

enum EthereumPrison
{
    SPELL_REP_LC        = 39456,
    SPELL_REP_SHAT      = 39457,
    SPELL_REP_CE        = 39460,
    SPELL_REP_CON       = 39474,
    SPELL_REP_KT        = 39475,
    SPELL_REP_SPOR      = 39476
};

const uint32 NpcPrisonEntry[] =
{
    22810, 22811, 22812, 22813, 22814, 22815,               //good guys
    20783, 20784, 20785, 20786, 20788, 20789, 20790         //bad guys
};

class go_ethereum_prison : public GameObjectScript
{
public:
    go_ethereum_prison() : GameObjectScript("go_ethereum_prison") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        go->UseDoorOrButton();
        int Random = rand() % (sizeof(NpcPrisonEntry) / sizeof(uint32));

        if (Creature* creature = player->SummonCreature(NpcPrisonEntry[Random], go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetAngle(player),
            TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
        {
            if (!creature->IsHostileTo(player))
            {
                if (FactionTemplateEntry const* pFaction = creature->getFactionTemplateEntry())
                {
                    uint32 Spell = 0;

                    switch (pFaction->faction)
                    {
                        case 1011: Spell = SPELL_REP_LC; break;
                        case 935: Spell = SPELL_REP_SHAT; break;
                        case 942: Spell = SPELL_REP_CE; break;
                        case 933: Spell = SPELL_REP_CON; break;
                        case 989: Spell = SPELL_REP_KT; break;
                        case 970: Spell = SPELL_REP_SPOR; break;
                    }

                    if (Spell)
                        creature->CastSpell(player, Spell, false);
                    else
                        sLog->outError(LOG_FILTER_TSCR, "go_ethereum_prison summoned Creature (entry %u) but faction (%u) are not expected by script.", creature->GetEntry(), creature->getFaction());
                }
            }
        }

        return false;
    }
};

/*######
## go_ethereum_stasis
######*/

const uint32 NpcStasisEntry[] =
{
    22825, 20888, 22827, 22826, 22828
};

class go_ethereum_stasis : public GameObjectScript
{
public:
    go_ethereum_stasis() : GameObjectScript("go_ethereum_stasis") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        go->UseDoorOrButton();
        int Random = rand() % (sizeof(NpcStasisEntry) / sizeof(uint32));

        player->SummonCreature(NpcStasisEntry[Random], go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetAngle(player),
            TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);

        return false;
    }
};

/*######
## go_resonite_cask
######*/

enum ResoniteCask
{
    NPC_GOGGEROC    = 11920
};

class go_resonite_cask : public GameObjectScript
{
public:
    go_resonite_cask() : GameObjectScript("go_resonite_cask") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            go->SummonCreature(NPC_GOGGEROC, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 300000);

        return false;
    }
};

/*######
## go_sacred_fire_of_life
######*/

#define NPC_ARIKARA  10882

class go_sacred_fire_of_life : public GameObjectScript
{
public:
    go_sacred_fire_of_life() : GameObjectScript("go_sacred_fire_of_life") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            player->SummonCreature(NPC_ARIKARA, -5008.338f, -2118.894f, 83.657f, 0.874f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);

        return true;
    }
};

/*######
## go_shrine_of_the_birds
######*/

enum ShrineOfTheBirds
{
    NPC_HAWK_GUARD      = 22992,
    NPC_EAGLE_GUARD     = 22993,
    NPC_FALCON_GUARD    = 22994,
    GO_SHRINE_HAWK      = 185551,
    GO_SHRINE_EAGLE     = 185547,
    GO_SHRINE_FALCON    = 185553
};

class go_shrine_of_the_birds : public GameObjectScript
{
public:
    go_shrine_of_the_birds() : GameObjectScript("go_shrine_of_the_birds") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        uint32 BirdEntry = 0;

        float fX, fY, fZ;
        go->GetClosePoint(fX, fY, fZ, go->GetObjectSize(), INTERACTION_DISTANCE);

        switch (go->GetEntry())
        {
            case GO_SHRINE_HAWK:
                BirdEntry = NPC_HAWK_GUARD;
                break;
            case GO_SHRINE_EAGLE:
                BirdEntry = NPC_EAGLE_GUARD;
                break;
            case GO_SHRINE_FALCON:
                BirdEntry = NPC_FALCON_GUARD;
                break;
        }

        if (BirdEntry)
            player->SummonCreature(BirdEntry, fX, fY, fZ, go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);

        return false;
    }
};

/*######
## go_southfury_moonstone
######*/

enum Southfury
{
    NPC_RIZZLE                  = 23002,
    SPELL_BLACKJACK             = 39865, //stuns player
    SPELL_SUMMON_RIZZLE         = 39866
};

class go_southfury_moonstone : public GameObjectScript
{
public:
    go_southfury_moonstone() : GameObjectScript("go_southfury_moonstone") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        //implicitTarget=48 not implemented as of writing this code, and manual summon may be just ok for our purpose
        //player->CastSpell(player, SPELL_SUMMON_RIZZLE, false);

        if (Creature* creature = player->SummonCreature(NPC_RIZZLE, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0))
            creature->CastSpell(player, SPELL_BLACKJACK, false);

        return false;
    }
};

/*######
## go_tele_to_dalaran_crystal
######*/

enum DalaranCrystal
{
    QUEST_LEARN_LEAVE_RETURN    = 12790,
    QUEST_TELE_CRYSTAL_FLAG     = 12845
};

#define GO_TELE_TO_DALARAN_CRYSTAL_FAILED   "This teleport crystal cannot be used until the teleport crystal in Dalaran has been used at least once."

class go_tele_to_dalaran_crystal : public GameObjectScript
{
public:
    go_tele_to_dalaran_crystal() : GameObjectScript("go_tele_to_dalaran_crystal") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->GetQuestRewardStatus(QUEST_TELE_CRYSTAL_FLAG))
            return false;

        player->GetSession()->SendNotification(GO_TELE_TO_DALARAN_CRYSTAL_FAILED);

        return true;
    }
};

/*######
## go_tele_to_violet_stand
######*/

class go_tele_to_violet_stand : public GameObjectScript
{
public:
    go_tele_to_violet_stand() : GameObjectScript("go_tele_to_violet_stand") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->GetQuestRewardStatus(QUEST_LEARN_LEAVE_RETURN) || player->GetQuestStatus(QUEST_LEARN_LEAVE_RETURN) == QUEST_STATUS_INCOMPLETE)
            return false;

        return true;
    }
};

/*######
## go_fel_crystalforge
######*/

#define GOSSIP_FEL_CRYSTALFORGE_TEXT 31000
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_TEXT_RETURN 31001
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_1 "Purchase 1 Unstable Flask of the Beast for the cost of 10 Apexis Shards"
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_5 "Purchase 5 Unstable Flask of the Beast for the cost of 50 Apexis Shards"
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_RETURN "Use the fel crystalforge to make another purchase."

enum FelCrystalforge
{
    SPELL_CREATE_1_FLASK_OF_BEAST   = 40964,
    SPELL_CREATE_5_FLASK_OF_BEAST   = 40965,
};

class go_fel_crystalforge : public GameObjectScript
{
public:
    go_fel_crystalforge() : GameObjectScript("go_fel_crystalforge") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER) /* != GAMEOBJECT_TYPE_QUESTGIVER) */
            player->PrepareQuestMenu(go->GetGUID()); /* return true*/

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        player->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_TEXT, go->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->CastSpell(player, SPELL_CREATE_1_FLASK_OF_BEAST, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_ITEM_TEXT_RETURN, go->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->CastSpell(player, SPELL_CREATE_5_FLASK_OF_BEAST, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_ITEM_TEXT_RETURN, go->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_TEXT, go->GetGUID());
                break;
        }
        return true;
    }
};

/*######
## go_bashir_crystalforge
######*/

#define GOSSIP_BASHIR_CRYSTALFORGE_TEXT 31100
#define GOSSIP_BASHIR_CRYSTALFORGE_ITEM_TEXT_RETURN 31101
#define GOSSIP_BASHIR_CRYSTALFORGE_ITEM_1 "Purchase 1 Unstable Flask of the Sorcerer for the cost of 10 Apexis Shards"
#define GOSSIP_BASHIR_CRYSTALFORGE_ITEM_5 "Purchase 5 Unstable Flask of the Sorcerer for the cost of 50 Apexis Shards"
#define GOSSIP_BASHIR_CRYSTALFORGE_ITEM_RETURN "Use the bashir crystalforge to make another purchase."

enum BashirCrystalforge
{
    SPELL_CREATE_1_FLASK_OF_SORCERER   = 40968,
    SPELL_CREATE_5_FLASK_OF_SORCERER   = 40970,
};

class go_bashir_crystalforge : public GameObjectScript
{
public:
    go_bashir_crystalforge() : GameObjectScript("go_bashir_crystalforge") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER) /* != GAMEOBJECT_TYPE_QUESTGIVER) */
            player->PrepareQuestMenu(go->GetGUID()); /* return true*/

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        player->SEND_GOSSIP_MENU(GOSSIP_BASHIR_CRYSTALFORGE_TEXT, go->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->CastSpell(player, SPELL_CREATE_1_FLASK_OF_SORCERER, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_BASHIR_CRYSTALFORGE_ITEM_TEXT_RETURN, go->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->CastSpell(player, SPELL_CREATE_5_FLASK_OF_SORCERER, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_BASHIR_CRYSTALFORGE_ITEM_TEXT_RETURN, go->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(GOSSIP_BASHIR_CRYSTALFORGE_TEXT, go->GetGUID());
                break;
        }
        return true;
    }
};

/*######
## matrix_punchograph
######*/

enum MatrixPunchograph
{
    ITEM_WHITE_PUNCH_CARD = 9279,
    ITEM_YELLOW_PUNCH_CARD = 9280,
    ITEM_BLUE_PUNCH_CARD = 9282,
    ITEM_RED_PUNCH_CARD = 9281,
    ITEM_PRISMATIC_PUNCH_CARD = 9316,
    SPELL_YELLOW_PUNCH_CARD = 11512,
    SPELL_BLUE_PUNCH_CARD = 11525,
    SPELL_RED_PUNCH_CARD = 11528,
    SPELL_PRISMATIC_PUNCH_CARD = 11545,
    MATRIX_PUNCHOGRAPH_3005_A = 142345,
    MATRIX_PUNCHOGRAPH_3005_B = 142475,
    MATRIX_PUNCHOGRAPH_3005_C = 142476,
    MATRIX_PUNCHOGRAPH_3005_D = 142696,
};

class go_matrix_punchograph : public GameObjectScript
{
public:
    go_matrix_punchograph() : GameObjectScript("go_matrix_punchograph") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        switch (go->GetEntry())
        {
            case MATRIX_PUNCHOGRAPH_3005_A:
                if (player->HasItemCount(ITEM_WHITE_PUNCH_CARD))
                {
                    player->DestroyItemCount(ITEM_WHITE_PUNCH_CARD, 1, true);
                    player->CastSpell(player, SPELL_YELLOW_PUNCH_CARD, true);
                }
                break;
            case MATRIX_PUNCHOGRAPH_3005_B:
                if (player->HasItemCount(ITEM_YELLOW_PUNCH_CARD))
                {
                    player->DestroyItemCount(ITEM_YELLOW_PUNCH_CARD, 1, true);
                    player->CastSpell(player, SPELL_BLUE_PUNCH_CARD, true);
                }
                break;
            case MATRIX_PUNCHOGRAPH_3005_C:
                if (player->HasItemCount(ITEM_BLUE_PUNCH_CARD))
                {
                    player->DestroyItemCount(ITEM_BLUE_PUNCH_CARD, 1, true);
                    player->CastSpell(player, SPELL_RED_PUNCH_CARD, true);
                }
                break;
            case MATRIX_PUNCHOGRAPH_3005_D:
                if (player->HasItemCount(ITEM_RED_PUNCH_CARD))
                {
                    player->DestroyItemCount(ITEM_RED_PUNCH_CARD, 1, true);
                    player->CastSpell(player, SPELL_PRISMATIC_PUNCH_CARD, true);
                }
                break;
            default:
                break;
        }
        return false;
    }
};

/*######
## go_scourge_cage
######*/

enum ScourgeCage
{
    NPC_SCOURGE_PRISONER = 25610
};

class go_scourge_cage : public GameObjectScript
{
public:
    go_scourge_cage() : GameObjectScript("go_scourge_cage") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        go->UseDoorOrButton();
        if (Creature* pNearestPrisoner = go->FindNearestCreature(NPC_SCOURGE_PRISONER, 5.0f, true))
        {
            player->KilledMonsterCredit(NPC_SCOURGE_PRISONER, pNearestPrisoner->GetGUID());
            pNearestPrisoner->DisappearAndDie();
        }

        return true;
    }
};

/*######
## go_arcane_prison
######*/

enum ArcanePrison
{
    QUEST_PRISON_BREAK                  = 11587,
    SPELL_ARCANE_PRISONER_KILL_CREDIT   = 45456
};

class go_arcane_prison : public GameObjectScript
{
public:
    go_arcane_prison() : GameObjectScript("go_arcane_prison") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_PRISON_BREAK) == QUEST_STATUS_INCOMPLETE)
        {
            go->SummonCreature(25318, 3485.089844f, 6115.7422188f, 70.966812f, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
            player->CastSpell(player, SPELL_ARCANE_PRISONER_KILL_CREDIT, true);
            return true;
        }
        return false;
    }
};

/*######
## go_blood_filled_orb
######*/

#define NPC_ZELEMAR  17830

class go_blood_filled_orb : public GameObjectScript
{
public:
    go_blood_filled_orb() : GameObjectScript("go_blood_filled_orb") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            player->SummonCreature(NPC_ZELEMAR, -369.746f, 166.759f, -21.50f, 5.235f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);

        return true;
    }
};

/*######
## go_jotunheim_cage
######*/

enum JotunheimCage
{
    NPC_EBON_BLADE_PRISONER_HUMAN   = 30186,
    NPC_EBON_BLADE_PRISONER_NE      = 30194,
    NPC_EBON_BLADE_PRISONER_TROLL   = 30196,
    NPC_EBON_BLADE_PRISONER_ORC     = 30195,

    SPELL_SUMMON_BLADE_KNIGHT_H     = 56207,
    SPELL_SUMMON_BLADE_KNIGHT_NE    = 56209,
    SPELL_SUMMON_BLADE_KNIGHT_ORC   = 56212,
    SPELL_SUMMON_BLADE_KNIGHT_TROLL = 56214
};

class go_jotunheim_cage : public GameObjectScript
{
public:
    go_jotunheim_cage() : GameObjectScript("go_jotunheim_cage") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        go->UseDoorOrButton();
        Creature* pPrisoner = go->FindNearestCreature(NPC_EBON_BLADE_PRISONER_HUMAN, 5.0f, true);
        if (!pPrisoner)
        {
            pPrisoner = go->FindNearestCreature(NPC_EBON_BLADE_PRISONER_TROLL, 5.0f, true);
            if (!pPrisoner)
            {
                pPrisoner = go->FindNearestCreature(NPC_EBON_BLADE_PRISONER_ORC, 5.0f, true);
                if (!pPrisoner)
                    pPrisoner = go->FindNearestCreature(NPC_EBON_BLADE_PRISONER_NE, 5.0f, true);
            }
        }
        if (!pPrisoner || !pPrisoner->isAlive())
            return false;

        pPrisoner->DisappearAndDie();
        player->KilledMonsterCredit(NPC_EBON_BLADE_PRISONER_HUMAN, 0);
        switch (pPrisoner->GetEntry())
        {
            case NPC_EBON_BLADE_PRISONER_HUMAN:
                player->CastSpell(player, SPELL_SUMMON_BLADE_KNIGHT_H, true);
                break;
            case NPC_EBON_BLADE_PRISONER_NE:
                player->CastSpell(player, SPELL_SUMMON_BLADE_KNIGHT_NE, true);
                break;
            case NPC_EBON_BLADE_PRISONER_TROLL:
                player->CastSpell(player, SPELL_SUMMON_BLADE_KNIGHT_TROLL, true);
                break;
            case NPC_EBON_BLADE_PRISONER_ORC:
                player->CastSpell(player, SPELL_SUMMON_BLADE_KNIGHT_ORC, true);
                break;
        }
        return true;
    }
};

enum TableTheka
{
    GOSSIP_TABLE_THEKA = 1653,

    QUEST_SPIDER_GOLD = 2936
};

class go_table_theka : public GameObjectScript
{
public:
    go_table_theka() : GameObjectScript("go_table_theka") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_SPIDER_GOLD) == QUEST_STATUS_INCOMPLETE)
            player->AreaExploredOrEventHappens(QUEST_SPIDER_GOLD);

        player->SEND_GOSSIP_MENU(GOSSIP_TABLE_THEKA, go->GetGUID());

        return true;
    }
};

/*######
## go_inconspicuous_landmark
######*/

enum InconspicuousLandmark
{
    SPELL_SUMMON_PIRATES_TREASURE_AND_TRIGGER_MOB    = 11462,
    ITEM_CUERGOS_KEY                                 = 9275,
};

class go_inconspicuous_landmark : public GameObjectScript
{
public:
    go_inconspicuous_landmark() : GameObjectScript("go_inconspicuous_landmark") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->HasItemCount(ITEM_CUERGOS_KEY))
            return false;

        player->CastSpell(player, SPELL_SUMMON_PIRATES_TREASURE_AND_TRIGGER_MOB, true);

        return true;
    }
};

/*######
## go_ethereal_teleport_pad
######*/

enum EtherealTeleportPad
{
    NPC_IMAGE_WIND_TRADER               = 20518,
    ITEM_TELEPORTER_POWER_PACK          = 28969,
};

class go_ethereal_teleport_pad : public GameObjectScript
{
public:
    go_ethereal_teleport_pad() : GameObjectScript("go_ethereal_teleport_pad") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (!player->HasItemCount(ITEM_TELEPORTER_POWER_PACK))
            return false;

        go->SummonCreature(NPC_IMAGE_WIND_TRADER, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetAngle(player), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);

        return true;
    }
};

/*######
## go_soulwell
######*/

enum SoulWellData
{
    GO_SOUL_WELL_R1                     = 181621,
    GO_SOUL_WELL_R2                     = 193169,

    SPELL_IMPROVED_HEALTH_STONE_R1      = 18692,
    SPELL_IMPROVED_HEALTH_STONE_R2      = 18693,

    SPELL_CREATE_MASTER_HEALTH_STONE_R0 = 34130,
    SPELL_CREATE_MASTER_HEALTH_STONE_R1 = 34149,
    SPELL_CREATE_MASTER_HEALTH_STONE_R2 = 34150,

    SPELL_CREATE_FEL_HEALTH_STONE_R0    = 58890,
    SPELL_CREATE_FEL_HEALTH_STONE_R1    = 58896,
    SPELL_CREATE_FEL_HEALTH_STONE_R2    = 58898,
};

class go_soulwell : public GameObjectScript
{
    public:
        go_soulwell() : GameObjectScript("go_soulwell") {}

        struct go_soulwellAI : public GameObjectAI
        {
            go_soulwellAI(GameObject* go) : GameObjectAI(go)
            {
                _stoneSpell = 0;
                _stoneId = 0;
                switch (go->GetEntry())
                {
                    case GO_SOUL_WELL_R1:
                        _stoneSpell = SPELL_CREATE_MASTER_HEALTH_STONE_R0;
                        if (Unit* owner = go->GetOwner())
                        {
                            if (owner->HasAura(SPELL_IMPROVED_HEALTH_STONE_R1))
                                _stoneSpell = SPELL_CREATE_MASTER_HEALTH_STONE_R1;
                            else if (owner->HasAura(SPELL_CREATE_MASTER_HEALTH_STONE_R2))
                                _stoneSpell = SPELL_CREATE_MASTER_HEALTH_STONE_R2;
                        }
                        break;
                    case GO_SOUL_WELL_R2:
                        _stoneSpell = SPELL_CREATE_FEL_HEALTH_STONE_R0;
                        if (Unit* owner = go->GetOwner())
                        {
                            if (owner->HasAura(SPELL_IMPROVED_HEALTH_STONE_R1))
                                _stoneSpell = SPELL_CREATE_FEL_HEALTH_STONE_R1;
                            else if (owner->HasAura(SPELL_CREATE_MASTER_HEALTH_STONE_R2))
                                _stoneSpell = SPELL_CREATE_FEL_HEALTH_STONE_R2;
                        }
                        break;
                }
                if (_stoneSpell == 0) // Should never happen
                    return;

                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(_stoneSpell);
                if (!spellInfo)
                    return;

                _stoneId = spellInfo->Effects[EFFECT_0].ItemType;
            }

            /// Due to the fact that this GameObject triggers CMSG_GAMEOBJECT_USE
            /// _and_ CMSG_GAMEOBJECT_REPORT_USE, this GossipHello hook is called
            /// twice. The script's handling is fine as it won't remove two charges
            /// on the well. We have to find how to segregate REPORT_USE and USE.
            bool GossipHello(Player* player)
            {
                Unit* owner = go->GetOwner();
                if (_stoneSpell == 0 || _stoneId == 0)
                    return true;

                if (!owner || owner->GetTypeId() != TYPEID_PLAYER || !player->IsInSameRaidWith(owner->ToPlayer()))
                    return true;

                // Don't try to add a stone if we already have one.
                if (player->HasItemCount(_stoneId))
                {
                    if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(_stoneSpell))
                        Spell::SendCastResult(player, spell, 0, SPELL_FAILED_TOO_MANY_OF_ITEM);
                    return true;
                }

                owner->CastSpell(player, _stoneSpell, true);
                // Item has to actually be created to remove a charge on the well.
                if (player->HasItemCount(_stoneId))
                    go->AddUse();

                return false;
            }

        private:
            uint32 _stoneSpell;
            uint32 _stoneId;
        };

        GameObjectAI* GetAI(GameObject* go) const
        {
            return new go_soulwellAI(go);
        }
};

/*######
## Quest 11255: Prisoners of Wyrmskull
## go_dragonflayer_cage
######*/

enum PrisonersOfWyrmskull
{
    QUEST_PRISONERS_OF_WYRMSKULL                  = 11255,
    NPC_PRISONER_PRIEST                           = 24086,
    NPC_PRISONER_MAGE                             = 24088,
    NPC_PRISONER_WARRIOR                          = 24089,
    NPC_PRISONER_PALADIN                          = 24090
};

class go_dragonflayer_cage : public GameObjectScript
{
public:
    go_dragonflayer_cage() : GameObjectScript("go_dragonflayer_cage") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(QUEST_PRISONERS_OF_WYRMSKULL) != QUEST_STATUS_INCOMPLETE)
            return true;

        Creature* pPrisoner = go->FindNearestCreature(NPC_PRISONER_PRIEST, 2.0f);
        if (!pPrisoner)
        {
            pPrisoner = go->FindNearestCreature(NPC_PRISONER_MAGE, 2.0f);
            if (!pPrisoner)
            {
                pPrisoner = go->FindNearestCreature(NPC_PRISONER_WARRIOR, 2.0f);
                if (!pPrisoner)
                    pPrisoner = go->FindNearestCreature(NPC_PRISONER_PALADIN, 2.0f);
            }
        }

        if (!pPrisoner || !pPrisoner->isAlive())
            return true;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(QUEST_PRISONERS_OF_WYRMSKULL);
        if (qInfo)
        {
            //TODO: prisoner should help player for a short period of time
            player->KilledMonsterCredit(qInfo->RequiredNpcOrGo[0], 0);
            pPrisoner->DisappearAndDie();
        }
        return true;
    }
};

/*######
## Quest 11560: Oh Noes, the Tadpoles!
## go_tadpole_cage
######*/

enum Tadpoles
{
    QUEST_OH_NOES_THE_TADPOLES                    = 11560,
    NPC_WINTERFIN_TADPOLE                         = 25201
};

class go_tadpole_cage : public GameObjectScript
{
public:
    go_tadpole_cage() : GameObjectScript("go_tadpole_cage") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(QUEST_OH_NOES_THE_TADPOLES) == QUEST_STATUS_INCOMPLETE)
        {
            Creature* pTadpole = go->FindNearestCreature(NPC_WINTERFIN_TADPOLE, 1.0f);
            if (pTadpole)
            {
                pTadpole->DisappearAndDie();
                player->KilledMonsterCredit(NPC_WINTERFIN_TADPOLE, 0);
                //FIX: Summon minion tadpole
            }
        }
        return true;
    }
};

/*######
## go_amberpine_outhouse
######*/

#define GOSSIP_USE_OUTHOUSE "Use the outhouse."
#define GO_ANDERHOLS_SLIDER_CIDER_NOT_FOUND "Quest item Anderhol's Slider Cider not found."

enum AmberpineOuthouse
{
    ITEM_ANDERHOLS_SLIDER_CIDER     = 37247,
    NPC_OUTHOUSE_BUNNY              = 27326,
    QUEST_DOING_YOUR_DUTY           = 12227,
    SPELL_INDISPOSED                = 53017,
    SPELL_INDISPOSED_III            = 48341,
    SPELL_CREATE_AMBERSEEDS         = 48330,
    GOSSIP_OUTHOUSE_INUSE           = 12775,
    GOSSIP_OUTHOUSE_VACANT          = 12779
};

class go_amberpine_outhouse : public GameObjectScript
{
public:
    go_amberpine_outhouse() : GameObjectScript("go_amberpine_outhouse") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        QuestStatus status = player->GetQuestStatus(QUEST_DOING_YOUR_DUTY);
        if (status == QUEST_STATUS_INCOMPLETE || status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_USE_OUTHOUSE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(GOSSIP_OUTHOUSE_VACANT, go->GetGUID());
            return true;
        }
        else
            player->SEND_GOSSIP_MENU(GOSSIP_OUTHOUSE_INUSE, go->GetGUID());
            return true;
    }

    bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF +1)
        {
            player->CLOSE_GOSSIP_MENU();
            Creature* target = GetClosestCreatureWithEntry(player, NPC_OUTHOUSE_BUNNY, 3.0f);
            if (target)
            {
                target->AI()->SetData(1, player->getGender());
                go->CastSpell(target, SPELL_INDISPOSED_III);
            }
            go->CastSpell(player, SPELL_INDISPOSED);
            if (player->HasItemCount(ITEM_ANDERHOLS_SLIDER_CIDER))
                go->CastSpell(player, SPELL_CREATE_AMBERSEEDS);
            return true;
        }
        else
        {
            player->CLOSE_GOSSIP_MENU();
            player->GetSession()->SendNotification(GO_ANDERHOLS_SLIDER_CIDER_NOT_FOUND);
            return false;
        }
    }
};

/*######
## Quest 1126: Hive in the Tower
## go_hive_pod
######*/

enum Hives
{
    QUEST_HIVE_IN_THE_TOWER                       = 9544,
    NPC_HIVE_AMBUSHER                             = 13301
};

class go_hive_pod : public GameObjectScript
{
public:
    go_hive_pod() : GameObjectScript("go_hive_pod") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        player->SendLoot(go->GetGUID(), LOOT_CORPSE);
        go->SummonCreature(NPC_HIVE_AMBUSHER, go->GetPositionX()+1, go->GetPositionY(), go->GetPositionZ(), go->GetAngle(player), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
        go->SummonCreature(NPC_HIVE_AMBUSHER, go->GetPositionX(), go->GetPositionY()+1, go->GetPositionZ(), go->GetAngle(player), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
        return true;
    }
};

class go_massive_seaforium_charge : public GameObjectScript
{
    public:
        go_massive_seaforium_charge() : GameObjectScript("go_massive_seaforium_charge") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go)
        {
            go->SetLootState(GO_JUST_DEACTIVATED);
            return true;
        }
};

/*######
## go_gjalerbron_cage
######*/

enum OfKeysAndCages
{
    QUEST_ALLIANCE_OF_KEYS_AND_CAGES    = 11231,
    QUEST_HORDE_OF_KEYS_AND_CAGES       = 11265,
    NPC_GJALERBRON_PRISONER             = 24035,
    SAY_FREE                            = 0,
};

class go_gjalerbron_cage : public GameObjectScript
{
    public:
        go_gjalerbron_cage() : GameObjectScript("go_gjalerbron_cage") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            go->UseDoorOrButton();
            if ((player->GetTeamId() == TEAM_ALLIANCE && player->GetQuestStatus(QUEST_ALLIANCE_OF_KEYS_AND_CAGES) == QUEST_STATUS_INCOMPLETE) ||
                (player->GetTeamId() == TEAM_HORDE && player->GetQuestStatus(QUEST_HORDE_OF_KEYS_AND_CAGES) == QUEST_STATUS_INCOMPLETE))
            {
                if (Creature* prisoner = go->FindNearestCreature(NPC_GJALERBRON_PRISONER, 5.0f))
                {
                    if (player)
                        player->KilledMonsterCredit(NPC_GJALERBRON_PRISONER, 0);

                    prisoner->AI()->Talk(SAY_FREE);
                    prisoner->DespawnOrUnsummon(6000);
                }
            }
            return true;
        }
};

/*########
## go_large_gjalerbron_cage
#####*/

class go_large_gjalerbron_cage : public GameObjectScript
{
    public:
        go_large_gjalerbron_cage() : GameObjectScript("go_large_gjalerbron_cage") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            go->UseDoorOrButton();
            if ((player->GetTeamId() == TEAM_ALLIANCE && player->GetQuestStatus(QUEST_ALLIANCE_OF_KEYS_AND_CAGES) == QUEST_STATUS_INCOMPLETE) ||
                (player->GetTeamId() == TEAM_HORDE && player->GetQuestStatus(QUEST_HORDE_OF_KEYS_AND_CAGES) == QUEST_STATUS_INCOMPLETE))
            {
                std::list<Creature*> prisonerList;
                GetCreatureListWithEntryInGrid(prisonerList, go, NPC_GJALERBRON_PRISONER, INTERACTION_DISTANCE);
                for (std::list<Creature*>::const_iterator itr = prisonerList.begin(); itr != prisonerList.end(); ++itr)
                {
                    player->KilledMonsterCredit(NPC_GJALERBRON_PRISONER, (*itr)->GetGUID());
                    (*itr)->DespawnOrUnsummon(6000);
                    (*itr)->AI()->Talk(SAY_FREE);
                }
            }
            return false;
        }
};

/*########
#### go_veil_skith_cage
#####*/

enum MissingFriends
{
   QUEST_MISSING_FRIENDS    = 10852,
   NPC_CAPTIVE_CHILD        = 22314,
   SAY_FREE_0               = 0,
};

class go_veil_skith_cage : public GameObjectScript
{
    public:
       go_veil_skith_cage() : GameObjectScript("go_veil_skith_cage") { }

       bool OnGossipHello(Player* player, GameObject* go)
       {
           go->UseDoorOrButton();
           if (player->GetQuestStatus(QUEST_MISSING_FRIENDS) == QUEST_STATUS_INCOMPLETE)
           {
               std::list<Creature*> childrenList;
               GetCreatureListWithEntryInGrid(childrenList, go, NPC_CAPTIVE_CHILD, INTERACTION_DISTANCE);
               for (std::list<Creature*>::const_iterator itr = childrenList.begin(); itr != childrenList.end(); ++itr)
               {
                   player->KilledMonsterCredit(NPC_CAPTIVE_CHILD, (*itr)->GetGUID());
                   (*itr)->DespawnOrUnsummon(5000);
                   (*itr)->GetMotionMaster()->MovePoint(1, go->GetPositionX()+5, go->GetPositionY(), go->GetPositionZ());
                   (*itr)->AI()->Talk(SAY_FREE_0);
                   (*itr)->GetMotionMaster()->Clear();
               }
           }
           return false;
       }
};

/*######
## go_frostblade_shrine
######*/

enum TheCleansing
{
   QUEST_THE_CLEANSING_HORDE      = 11317,
   QUEST_THE_CLEANSING_ALLIANCE   = 11322,
   SPELL_CLEANSING_SOUL           = 43351,
   SPELL_RECENT_MEDITATION        = 61720,
};

class go_frostblade_shrine : public GameObjectScript
{
public:
    go_frostblade_shrine() : GameObjectScript("go_frostblade_shrine") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        go->UseDoorOrButton(10);
        if (!player->HasAura(SPELL_RECENT_MEDITATION))
            if (player->GetQuestStatus(QUEST_THE_CLEANSING_HORDE) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_THE_CLEANSING_ALLIANCE) == QUEST_STATUS_INCOMPLETE)
            {
                player->CastSpell(player, SPELL_CLEANSING_SOUL);
                player->SetStandState(UNIT_STAND_STATE_SIT);
            }
            return true;
    }
};

/*######
## go_midsummer_bonfire
######*/

enum MidsummerBonfire
{
    STAMP_OUT_BONFIRE_QUEST_COMPLETE    = 45458,
};

class go_midsummer_bonfire : public GameObjectScript
{
public:
    go_midsummer_bonfire() : GameObjectScript("go_midsummer_bonfire") { }

    bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 /*sender*/, uint32 /*action*/)
    {
        player->CastSpell(player, STAMP_OUT_BONFIRE_QUEST_COMPLETE, true);
        player->CLOSE_GOSSIP_MENU();
        return false;
    }
};

class go_marble_slab : public GameObjectScript
{
public:
    go_marble_slab() : GameObjectScript("go_marble_slab") { }

    enum Id
    {
        // Quest
        QUEST_ENTRY_SENTINEL_GAME_H     = 27886,
        QUEST_ENTRY_SENTIENL_GAME_A     = 27709,

        // Spell
        SPELL_SENTINEL_START_PAWN       = 86429,
        SPELL_SENTINEL_PAWN_01          = 86431,
        SPELL_SENTINEL_PAWN_02          = 86546,
        SPELL_SENTINEL_PAWN_03          = 86547,
        SPELL_SENTINEL_PAWN_04          = 86548,
        SPELL_SENTINEL_PAWN_05          = 86549,
        SPELL_SENTINEL_PAWN_06          = 86550,
        SPELL_SENTINEL_PAWN_07          = 86551,
        SPELL_SENTINEL_PAWN_08          = 86552,
        SPELL_SENTINEL_PAWN_09          = 86553,
        SPELL_SENTINEL_DESPAWN          = 86555
    };

    bool OnQuestAccept(Player* player, GameObject* go, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_ENTRY_SENTINEL_GAME_H || quest->GetQuestId() == QUEST_ENTRY_SENTIENL_GAME_A)
        {
            player->CastSpell(player, SPELL_SENTINEL_DESPAWN, true);
            player->CastSpell(player, SPELL_SENTINEL_START_PAWN, true);
            player->CastSpell(player, SPELL_SENTINEL_PAWN_01, true);
            player->CastSpell(player, SPELL_SENTINEL_PAWN_02, true);
            player->CastSpell(player, SPELL_SENTINEL_PAWN_03, true);
            player->CastSpell(player, SPELL_SENTINEL_PAWN_04, true);
            player->CastSpell(player, SPELL_SENTINEL_PAWN_05, true);
            player->CastSpell(player, SPELL_SENTINEL_PAWN_06, true);
            player->CastSpell(player, SPELL_SENTINEL_PAWN_07, true);
            player->CastSpell(player, SPELL_SENTINEL_PAWN_08, true);
            player->CastSpell(player, SPELL_SENTINEL_PAWN_09, true);
        }
        return true;
    }
};

class go_ajamon_portal_start : public GameObjectScript
{
public:
    go_ajamon_portal_start() : GameObjectScript("go_ajamon_portal_start") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(25704) == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(player, 52096, true);
            player->TeleportTo(1, -6668.65f, -4220.67f, 86.12f, 1.42f);
            return true;
        }
        return false;
    }
};

class go_ajamon_portal_return : public GameObjectScript
{
public:
    go_ajamon_portal_return() : GameObjectScript("go_ajamon_portal_return") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(25704) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(25704) == QUEST_STATUS_COMPLETE)
        {
            player->CastSpell(player, 52096, true);
            player->TeleportTo(1, -6086.65f, -4700.21f, 93.57f, 1.85f);
            return true;
        }
        return false;
    }
};

class go_horn_mouthpiece : public GameObjectScript
{
public:
    go_horn_mouthpiece() : GameObjectScript("go_horn_mouthpiece") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(25813) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(25814) == QUEST_STATUS_INCOMPLETE)
        {
            player->PlayDirectSound(7234);
            Creature* Whrrrl = player->FindNearestCreature(41334, 200.0f, true);
            if (!Whrrrl)
                player->SummonCreature(41334, -5302.14f, -4378.71f, 140.14f, 2.85f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
            return false;
        }
        return true;
    }
};

class go_harpy_signal_fire : public GameObjectScript
{
public:
    go_harpy_signal_fire() : GameObjectScript("go_harpy_signal_fire") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(25731) == QUEST_STATUS_INCOMPLETE)
        {
            if (!player->HasAura(79203))
            {
                player->CastSpell(player, 77041, true);
                player->CastSpell(player, 79203, true);
            }
            return false;
        }
        return true;
    }
};

class go_shadow_cloak_generator : public GameObjectScript
{
public:
    go_shadow_cloak_generator() : GameObjectScript("go_shadow_cloak_generator") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(25764) == QUEST_STATUS_INCOMPLETE)
        {
            // Chance to summon hatchling
            if (roll_chance_f(80.0f))
                go->CastSpell(player, 77294);
            else
            {
                // Summon Aviana's Egg and Thisalee
                go->CastSpell(player, 77308);
                player->CastSpell(player, 77309);
            }
            go->SetGoAnimProgress(GO_STATE_READY);
            return false;
        }
        return true;
    }
};

class go_hyjal_flameward : public GameObjectScript
{
public:
    go_hyjal_flameward() : GameObjectScript("go_hyjal_flameward") { }

    enum Id
    {
        QUEST_ENTRY_PREPPING_THE_SOIL   = 25502,
        SPELL_FLAMEWARD_ACTIVATED       = 75470,
        NPC_ENTRY_FLAMEWARD_ACTIVATED   = 40461,
        NPC_LAVA_SURGERS                = 46911
    };

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_ENTRY_PREPPING_THE_SOIL) == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(player, SPELL_FLAMEWARD_ACTIVATED, true);
            player->MonsterWhisper("Defend the flameward!", player->GetGUID(), true);
            player->SummonCreature(NPC_ENTRY_FLAMEWARD_ACTIVATED, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 61000, const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(64)));

            // Call lava surgers
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, player, NPC_LAVA_SURGERS, 60.0f);
            if (!creatures.empty())
            {
                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    (*iter)->ToCreature()->Attack(player, true);
            }
            return false;
        }
        return true;
    }
};

class go_twilight_weapon_rack : public GameObjectScript
{
public:
    go_twilight_weapon_rack() : GameObjectScript("go_twilight_weapon_rack") { }

    enum Id
    {
        QUEST_ENTRY_FLIGHT_IN_THE_FIRELANDS = 25523,
        QUEST_ENTRY_WAVE_ONE                = 25525,
        QUEST_ENTRY_WAVE_TWO                = 25544,
        QUEST_ENTRY_EGG_WAVE                = 25560,
        ITEM_ENTRY_TWILIGHT_FIRELANCE       = 52716
    };

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_ENTRY_FLIGHT_IN_THE_FIRELANDS) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_ENTRY_WAVE_ONE) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_ENTRY_WAVE_TWO) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_ENTRY_EGG_WAVE) == QUEST_STATUS_INCOMPLETE)
        {
            if (!player->HasItemCount(ITEM_ENTRY_TWILIGHT_FIRELANCE, 1))
                player->MonsterWhisper("Equip the Lance", player->GetGUID(), true);
            return false;
        }
        return true;
    }
};

class go_ball_and_chain : public GameObjectScript
{
public:
    go_ball_and_chain() : GameObjectScript("go_ball_and_chain") { }

    enum Id
    {
        QUEST_ENTRY_QUESTION_THE_SLAVES     = 26261,
        NPC_ENTRY_ENSLAVED_MINER            = 44768
    };

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_ENTRY_QUESTION_THE_SLAVES) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature* enslavedMiner = player->FindNearestCreature(NPC_ENTRY_ENSLAVED_MINER, 10.0f, true))
                enslavedMiner->AI()->SetData(0, 1);
            return false;
        }
        return true;
    }
};

class go_waygate_controller : public GameObjectScript
{
public:
    go_waygate_controller() : GameObjectScript("go_waygate_controller") { }

    enum Id
    {
        QUEST_THE_WRONG_SEQUENCE_A      = 27058,
        QUEST_THE_WRONG_SEQUENCE_H      = 27059,
        SPELL_BIG_GATE_EXPLOSION        = 88649,
        EXPLOSION_TRIGGER               = 24110,
        GO_WAYGATE_FIRE                 = 205196
    };

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_THE_WRONG_SEQUENCE_A) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_WRONG_SEQUENCE_H) == QUEST_STATUS_INCOMPLETE)
        {
            std::list<Creature*> explTriggers;
            GetCreatureListWithEntryInGrid(explTriggers, go, EXPLOSION_TRIGGER, 50.0f);
            if (explTriggers.empty())
                return false;

            for (std::list<Creature*>::iterator itr = explTriggers.begin(); itr != explTriggers.end(); ++itr)
                (*itr)->CastWithDelay(urand(1000, 5000), (*itr), SPELL_BIG_GATE_EXPLOSION, true);

            std::list<GameObject*> fireTriggers;
            GetGameObjectListWithEntryInGrid(fireTriggers, go, GO_WAYGATE_FIRE, 50.0f);
            if (fireTriggers.empty())
                return false;

            for (std::list<GameObject*>::iterator itr = fireTriggers.begin(); itr != fireTriggers.end(); ++itr)
            {
                (*itr)->SetPhaseMask(1, true);
                (*itr)->SetRespawnTime(15000);
            }
            return false;
        }
        return true;
    }
};

class go_twilight_portal_deepholm : public GameObjectScript
{
    public:
        go_twilight_portal_deepholm() : GameObjectScript("go_twilight_portal_deepholm") {}

        enum goGUID
        {
            GUID_FINAL_PHASE_1  = 719178,
            GUID_FINAL_PHASE_2  = 719179,
            GUID_FINAL_PHASE_3  = 719180
        };

        enum npcId
        {
            NPC_TWILIGHT_DEFILER        = 44680,
            NPC_TWILIGHT_HERETIC        = 44681,
            NPC_DESECRATED_EARTHRAGER   = 44683
        };

        enum eventId
        {
            EVENT_SUMMON_HERETIC    = 1,
            EVENT_SUMMON_DEFILER,
            EVENT_SUMMON_EARTHRAGER
        };

        struct go_twilight_portal_deepholmAI : public GameObjectAI
        {
            EventMap events;

            go_twilight_portal_deepholmAI(GameObject* go) : GameObjectAI(go)
            {
                events.ScheduleEvent(EVENT_SUMMON_HERETIC, urand(45000, 75000));
                events.ScheduleEvent(EVENT_SUMMON_DEFILER, urand(55000, 85000));
                events.ScheduleEvent(EVENT_SUMMON_EARTHRAGER, 90000);
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_HERETIC:
                        {
                            if (go->GetGUIDLow() == GUID_FINAL_PHASE_1 ||
                                go->GetGUIDLow() == GUID_FINAL_PHASE_2 ||
                                go->GetGUIDLow() == GUID_FINAL_PHASE_3)
                            {
                                break;
                            }
                            SummonHeretics();
                            events.ScheduleEvent(EVENT_SUMMON_HERETIC, urand(45000, 75000));
                            break;
                        }
                        case EVENT_SUMMON_DEFILER:
                        {
                            if (go->GetGUIDLow() == GUID_FINAL_PHASE_1 ||
                                go->GetGUIDLow() == GUID_FINAL_PHASE_2 ||
                                go->GetGUIDLow() == GUID_FINAL_PHASE_3)
                            {
                                break;
                            }
                            SummonDefilers();
                            events.ScheduleEvent(EVENT_SUMMON_DEFILER, urand(55000, 85000));
                            break;
                        }
                        case EVENT_SUMMON_EARTHRAGER:
                        {
                            if (go->GetGUIDLow() == GUID_FINAL_PHASE_1 ||
                                go->GetGUIDLow() == GUID_FINAL_PHASE_2 ||
                                go->GetGUIDLow() == GUID_FINAL_PHASE_3)
                            {
                                break;
                            }
                            go->SummonCreature(NPC_DESECRATED_EARTHRAGER, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 45000);
                            events.ScheduleEvent(EVENT_SUMMON_EARTHRAGER, urand(60000, 90000));
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void SummonHeretics()
            {
                go->SummonCreature(NPC_TWILIGHT_HERETIC, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 45000);
                go->SummonCreature(NPC_TWILIGHT_HERETIC, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 45000);
                go->SummonCreature(NPC_TWILIGHT_HERETIC, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 45000);
            }

            void SummonDefilers()
            {
                go->SummonCreature(NPC_TWILIGHT_DEFILER, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 45000);
                go->SummonCreature(NPC_TWILIGHT_DEFILER, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 45000);
                go->SummonCreature(NPC_TWILIGHT_DEFILER, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 45000);
            }
        };

        GameObjectAI* GetAI(GameObject* go) const
        {
            return new go_twilight_portal_deepholmAI(go);
        }
};

void AddSC_go_scripts()
{
    new go_cat_figurine;
    new go_northern_crystal_pylon;
    new go_eastern_crystal_pylon;
    new go_western_crystal_pylon;
    new go_barov_journal;
    new go_field_repair_bot_74A;
    new go_gilded_brazier;
    new go_orb_of_command;
    new go_shrine_of_the_birds;
    new go_southfury_moonstone;
    new go_tablet_of_madness;
    new go_tablet_of_the_seven;
    new go_jump_a_tron;
    new go_ethereum_prison;
    new go_ethereum_stasis;
    new go_resonite_cask;
    new go_sacred_fire_of_life;
    new go_tele_to_dalaran_crystal;
    new go_tele_to_violet_stand;
    new go_fel_crystalforge;
    new go_bashir_crystalforge;
    new go_matrix_punchograph;
    new go_scourge_cage;
    new go_arcane_prison;
    new go_blood_filled_orb;
    new go_jotunheim_cage;
    new go_table_theka;
    new go_inconspicuous_landmark;
    new go_ethereal_teleport_pad;
    new go_soulwell;
    new go_tadpole_cage;
    new go_dragonflayer_cage;
    new go_amberpine_outhouse;
    new go_hive_pod;
    new go_massive_seaforium_charge;
    new go_gjalerbron_cage;
    new go_large_gjalerbron_cage;
    new go_veil_skith_cage;
    new go_frostblade_shrine;
    new go_midsummer_bonfire;
    new go_marble_slab;
    new go_ajamon_portal_return;
    new go_ajamon_portal_start;
    new go_horn_mouthpiece;
    new go_harpy_signal_fire;
    new go_shadow_cloak_generator;
    new go_hyjal_flameward;
    new go_twilight_weapon_rack;
    new go_ball_and_chain;
    new go_waygate_controller;
    new go_twilight_portal_deepholm;
}

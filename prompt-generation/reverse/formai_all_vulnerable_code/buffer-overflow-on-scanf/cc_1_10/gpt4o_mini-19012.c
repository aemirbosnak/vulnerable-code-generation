//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LEN 30
#define MAX_ACTIONS 5

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int hackingSkill;
    int combatSkill;
} Player;

typedef struct {
    char description[100];
    int dangerLevel;
} Encounter;

void initializePlayers(Player players[], int playerCount);
void displayPlayerStats(Player player);
void generateEncounter(Encounter *encounter);
void engageInCombat(Player *player, Encounter encounter);
void hackSystem(Player *player, Encounter encounter);
void takeAction(Player *player, Encounter encounter);

int main() {
    srand(time(0));
    
    int numPlayers;
    printf("Welcome to Cyberpunk Encounter!\n");
    printf("Enter number of players (1 - 4): ");
    scanf("%d", &numPlayers);
    while(numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 1 and 4: ");
        scanf("%d", &numPlayers);
    }

    Player players[MAX_PLAYERS];
    initializePlayers(players, numPlayers);

    for(int i = 0; i < numPlayers; i++) {
        printf("\n%s's turn:\n", players[i].name);
        Encounter encounter;
        generateEncounter(&encounter);
        printf("Encounter: %s (Danger Level: %d)\n", encounter.description, encounter.dangerLevel);
        takeAction(&players[i], encounter);
        displayPlayerStats(players[i]);
    }

    printf("\nGame Over! Thanks for playing!\n");
    return 0;
}

void initializePlayers(Player players[], int playerCount) {
    for(int i = 0; i < playerCount; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].health = 100;
        players[i].hackingSkill = rand() % 100 + 1; // Random skill between 1 and 100
        players[i].combatSkill = rand() % 100 + 1; // Random skill between 1 and 100
    }
}

void displayPlayerStats(Player player) {
    printf("\nStats for %s:\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Hacking Skill: %d\n", player.hackingSkill);
    printf("Combat Skill: %d\n", player.combatSkill);
}

void generateEncounter(Encounter *encounter) {
    const char *descriptions[] = {
        "A group of hostile cyborgs",
        "A corrupt corporate security system",
        "A malfunctioning AI that needs to be shut down",
        "An underground street gang",
        "A rogue drone swarm"
    };

    encounter->dangerLevel = rand() % 100 + 1; // Random danger level between 1 and 100
    strcpy(encounter->description, descriptions[rand() % (sizeof(descriptions) / sizeof(descriptions[0]))]);
}

void engageInCombat(Player *player, Encounter encounter) {
    printf("%s decides to engage in combat!\n", player->name);
    if (player->combatSkill > encounter.dangerLevel) {
        printf("Combat successful! You defeated the enemies!\n");
    } else {
        player->health -= (encounter.dangerLevel - player->combatSkill);
        printf("You were hit! Health reduced to %d.\n", player->health);
    }
}

void hackSystem(Player *player, Encounter encounter) {
    printf("%s attempts to hack the system!\n", player->name);
    if (player->hackingSkill > encounter.dangerLevel) {
        printf("Hacking successful! You have neutralized the threat!\n");
    } else {
        player->health -= (encounter.dangerLevel - player->hackingSkill);
        printf("Hacking attempt failed! Health reduced to %d.\n", player->health);
    }
}

void takeAction(Player *player, Encounter encounter) {
    int actionChoice;
    printf("Choose your action:\n");
    printf("1. Engage in Combat\n");
    printf("2. Hack the System\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &actionChoice);

    if(actionChoice == 1) {
        engageInCombat(player, encounter);
    } else if(actionChoice == 2) {
        hackSystem(player, encounter);
    } else {
        printf("Invalid choice. No action taken.\n");
    }
}
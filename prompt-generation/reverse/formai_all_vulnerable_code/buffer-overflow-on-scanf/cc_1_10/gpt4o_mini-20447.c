//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LEN 20
#define MAX_ACTION_LEN 100
#define GAME_ROUNDS 5

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int cyberware_points;
    int credits;
} Player;

void displayWelcome() {
    printf("===============================================\n");
    printf("        WELCOME TO CYBERPUNK TABLE GAME       \n");
    printf("===============================================\n");
}

void initializePlayers(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", (i + 1));
        fgets(players[i].name, MAX_NAME_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline
        players[i].health = 100;
        players[i].cyberware_points = 0;
        players[i].credits = 500; // starting credits
    }
}

void displayPlayers(Player players[], int num_players) {
    printf("\nCurrent Player Status:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s | Health: %d | Cyberware Points: %d | Credits: %d\n", 
               players[i].name, players[i].health, players[i].cyberware_points, players[i].credits);
    }
    printf("===============================================\n");
}

void performAction(Player *player) {
    int action;
    printf("Choose an action for %s:\n", player->name);
    printf("1. Hack the System\n2. Upgrade Cyberware\n3. Buy Information\n4. Fight Rival\n");
    printf("Enter action number: ");
    scanf("%d", &action);

    switch (action) {
        case 1: // Hack the System
            {
                int success = rand() % 2; // 50% chance to succeed
                if (success) {
                    player->cyberware_points += 10;
                    printf("%s successfully hacked the system! Earned 10 Cyberware Points.\n", player->name);
                } else {
                    player->health -= 20;
                    printf("%s failed to hack the system! Lost 20 Health.\n", player->name);
                }
            }
            break;
        case 2: // Upgrade Cyberware
            {
                if (player->credits >= 100) {
                    player->cyberware_points += 20;
                    player->credits -= 100;
                    printf("%s upgraded their cyberware! Earned 20 Cyberware Points. Remaining credits: %d\n", 
                           player->name, player->credits);
                } else {
                    printf("Not enough credits to upgrade cyberware!\n");
                }
            }
            break;
        case 3: // Buy Information
            {
                if (player->credits >= 50) {
                    player->credits -= 50;
                    printf("%s bought valuable information! 50 credits deducted. Remaining credits: %d\n", 
                           player->name, player->credits);
                } else {
                    printf("Not enough credits to buy information!\n");
                }
            }
            break;
        case 4: // Fight Rival
            {
                int rival_health = 50; // Simple rival model
                while (player->health > 0 && rival_health > 0) {
                    int player_damage = rand() % 20 + 10; // Damage between 10-30
                    rival_health -= player_damage;
                    printf("%s dealt %d damage to the rival! Rival health: %d\n", player->name, player_damage, rival_health);
                    if (rival_health <= 0) {
                        printf("%s defeated the rival!\n", player->name);
                        player->credits += 200;
                        printf("Earned 200 credits. Total credits: %d\n", player->credits);
                        break;
                    }
                    int rival_damage = rand() % 15 + 5; // Rival damage between 5-20
                    player->health -= rival_damage;
                    printf("Rival dealt %d damage to %s! Player health: %d\n", rival_damage, player->name, player->health);
                }
                if (player->health <= 0) {
                    printf("%s has been defeated...\n", player->name);
                }
            }
            break;
        default:
            printf("Invalid action!\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int num_players;

    displayWelcome();
    printf("Enter the number of players (2-4): ");
    scanf("%d", &num_players);
    getchar(); // consume new line
    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    initializePlayers(players, num_players);

    for (int round = 0; round < GAME_ROUNDS; round++) {
        printf("\n=== Round %d ===\n", round + 1);
        for (int i = 0; i < num_players; i++) {
            displayPlayers(players, num_players);
            performAction(&players[i]);
        }
    }

    printf("\nGame Over! Final Player Status:\n");
    displayPlayers(players, num_players);

    return 0;
}
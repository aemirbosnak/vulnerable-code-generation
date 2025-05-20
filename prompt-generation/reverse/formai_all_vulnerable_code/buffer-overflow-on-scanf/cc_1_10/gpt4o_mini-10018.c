//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int health;
    int gold;
} Player;

void initPlayer(Player *player) {
    printf("Enter your character's name: ");
    fgets(player->name, MAX_LENGTH, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline character
    player->health = 100;
    player->gold = 0;
}

void printStatus(Player *player) {
    printf("\n----- Player Status -----\n");
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Gold: %d\n", player->gold);
    printf("-------------------------\n");
}

void encounterMonster(Player *player) {
    printf("\nA wild monster appears!\n");
    printf("You engage in battle...\n");

    // Simulating battle
    player->health -= 20;
    printf("You got hit! Your health is now %d.\n", player->health);
    
    if (player->health <= 0) {
        printf("You have been defeated! Game Over!\n");
        exit(0);
    } else {
        printf("You fought bravely and defeated the monster!\n");
        player->gold += 50;
    }
}

void visitMarket(Player *player) {
    int choice;
    printf("\nWelcome to the market! You have %d gold.\n", player->gold);
    printf("1. Buy Health Potion (20 gold)\n");
    printf("2. Leave Market\n");
    
    printf("Choose an option: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            if (player->gold >= 20) {
                player->gold -= 20;
                player->health += 30;
                printf("You bought a Health Potion! Your health is now %d.\n", player->health);
            } else {
                printf("You don't have enough gold!\n");
            }
            break;
        case 2:
            printf("Leaving the market...\n");
            break;
        default:
            printf("Invalid option! Returning to the main adventure.\n");
    }
}

void explore(Player *player) {
    srand(time(0));
    int encounter = rand() % 3;

    printf("\nYou decide to explore the world...\n");

    switch (encounter) {
        case 0:
            encounterMonster(player);
            break;
        case 1:
            printf("You found some gold on the ground!\n");
            player->gold += 20;
            printf("You now have %d gold.\n", player->gold);
            break;
        case 2:
            printf("It's a peaceful day. You enjoy a brief rest and recover your spirits.\n");
            player->health += 10;
            if (player->health > 100) player->health = 100;
            printf("Your health is now %d.\n", player->health);
            break;
    }
}

int main() {
    Player player;
    char command[MAX_LENGTH];

    initPlayer(&player);
    
    while (1) {
        printStatus(&player);
        printf("What would you like to do? (explore, market, quit): ");
        fgets(command, MAX_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "explore") == 0) {
            explore(&player);
        } else if (strcmp(command, "market") == 0) {
            visitMarket(&player);
        } else if (strcmp(command, "quit") == 0) {
            printf("Thanks for playing! Goodbye, %s!\n", player.name);
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
    }

    return 0;
}
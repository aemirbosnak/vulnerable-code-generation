//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>   // Included for standard input and output operations
#include <stdlib.h>  // Included for the rand() function
#include <time.h>    // Included for time() function to seed the random number generator

int main() {
    int playerHealth = 100;  // The player's initial health
    int monsterHealth = 50;  // The monster's initial health
    int playerAttack;        // The player's attack damage
    int monsterAttack;       // The monster's attack damage
    int playerChoice;        // The player's choice in battle
    int fleeChance = 0;      // The chance to flee from battle
    int monsterType;         // The type of monster that the player encounters

    srand(time(NULL));  // Seed the random number generator with the current time

    printf("Welcome to the Haunted House Simulator!\n");

    while (playerHealth > 0) {  // The game loop
        monsterType = rand() % 3 + 1;  // Generate a random monster type (1-3)
        switch (monsterType) {
            case 1:
                printf("You have encountered a ghost!\n");
                monsterHealth = 50;
                break;
            case 2:
                printf("You have encountered a zombie!\n");
                monsterHealth = 75;
                break;
            case 3:
                printf("You have encountered a werewolf!\n");
                monsterHealth = 100;
                break;
        }

        while (monsterHealth > 0) {  // The battle loop
            printf("Your health: %d\n", playerHealth);
            printf("Monster health: %d\n", monsterHealth);
            printf("What do you want to do?\n");
            printf("1. Attack\n");
            printf("2. Flee\n");
            scanf("%d", &playerChoice);

            switch (playerChoice) {
                case 1:
                    playerAttack = rand() % 15 + 5;  // Generate a random attack damage (5-20)
                    monsterHealth -= playerAttack;
                    printf("You deal %d damage to the monster!\n", playerAttack);
                    break;
                case 2:
                    fleeChance = rand() % 3 + 1;  // Generate a random flee chance (1-3)
                    if (fleeChance == 1) {
                        printf("You successfully flee from the monster!\n");
                        monsterHealth = 0;
                    } else {
                        printf("You failed to flee from the monster!\n");
                        monsterAttack = rand() % 20 + 5;  // Generate a random monster attack damage (5-25)
                        playerHealth -= monsterAttack;
                        printf("The monster deals %d damage to you!\n", monsterAttack);
                    }
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }

            if (monsterHealth <= 0) {
                printf("You have defeated the monster!\n");
                break;
            }

            monsterAttack = rand() % 20 + 5;  // Generate a random monster attack damage (5-25)
            playerHealth -= monsterAttack;
            printf("The monster deals %d damage to you!\n", monsterAttack);

            if (playerHealth <= 0) {  // Check if the player has been defeated
                printf("You have been defeated by the monster :(\n");
                break;
            }
        }

        if (playerHealth <= 0) {  // Check if the player has been defeated
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}
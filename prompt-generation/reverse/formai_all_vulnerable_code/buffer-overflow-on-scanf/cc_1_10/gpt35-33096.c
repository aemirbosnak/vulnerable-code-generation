//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set random seed

    // Initialize variables
    int playerHP = 100;
    int monsterHP = 100;
    int playerAttack, monsterAttack;
    int choice, runChance;
    char name[20];

    // Introduction
    printf("Welcome to Medieval Adventure Game!\n");
    printf("-----------------------------------\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome, %s! You have %d HP and are ready to begin your adventure.\n", name, playerHP);
    printf("You are walking through a dense forest and suddenly encounter a fearsome monster!\n");

    // Main game loop
    while (playerHP > 0 && monsterHP > 0) {
        printf("\n%s HP: %d\tMonster HP: %d\n", name, playerHP, monsterHP);
        printf("What will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Player attacks
        if (choice == 1) {
            playerAttack = rand() % 20 + 1; // random attack strength
            printf("You attack the monster for %d damage!\n", playerAttack);
            monsterHP -= playerAttack;
        }
        // Player defends
        else if (choice == 2) {
            printf("You defend yourself and prepare for the monster's attack.\n");
        }
        // Player runs
        else if (choice == 3) {
            runChance = rand() % 2; // 50% chance of escaping
            if (runChance == 0) {
                printf("You tried to run but the monster caught you and dealt 20 damage!\n");
                playerHP -= 20;
            }
            else {
                printf("You successfully escaped from the monster!\n");
                break; // end game loop
            }
        }
        // Invalid choice
        else {
            printf("Invalid choice. Try again.\n");
            continue; // go back to start of loop
        }

        // Monster attacks
        if (monsterHP > 0) {
            monsterAttack = rand() % 15 + 1; // random attack strength
            printf("The monster attacks you for %d damage!\n", monsterAttack);
            playerHP -= monsterAttack;
        }
    }

    // Game over
    if (playerHP <= 0) {
        printf("\n%s HP: %d\tMonster HP: %d\n", name, playerHP, monsterHP);
        printf("You have been defeated by the monster. Game over.\n");
    }
    else {
        printf("\n%s HP: %d\tMonster HP: %d\n", name, playerHP, monsterHP);
        printf("Congratulations, you have defeated the monster and won the game!\n");
    }

    return 0;
}
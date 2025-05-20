//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char playerName[50];
    int playerScore = 0;
    int playerHealth = 100;
    int playerGold = 0;
    int playerXP = 0;
    int playerLevel = 1;
    char playerClass[20];

    // Introduction
    printf("Welcome to Adventure Game! Please enter your name: ");
    scanf("%s", playerName);
    printf("Welcome %s! What is your class? (Warrior, Mage, Rogue): ", playerName);
    scanf("%s", playerClass);
    printf("Great! You are a %s.\n", playerClass);

    printf("\nYou are standing at the entrance of a dungeon. You can hear some noises from within and feel a sense of adventure. Do you want to enter? (Yes/No)\n");

    char choice[5];
    scanf("%s", choice);

    if (strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0) {
        printf("\nYou enter the dungeon and find yourself in a dark corridor. You can barely see anything. What will you do? (Proceed/Retreat)\n");

        scanf("%s", choice);

        if (strcmp(choice, "Proceed") == 0 || strcmp(choice, "proceed") == 0) {
            printf("\nYou walk deeper into the dungeon and encounter a monster! What will you do? (Fight/Flee)\n");

            scanf("%s", choice);

            if (strcmp(choice, "Fight") == 0 || strcmp(choice, "fight") == 0) {
                printf("\nYou engage the monster in battle.");

                // Battle code goes here

                playerScore += 10;
                playerXP += 20;

                printf("\nYou have won the battle! Your score is now %d and your XP is now %d.\n", playerScore, playerXP);

                printf("\nYou continue deeper into the dungeon and find a hidden treasure! You receive 50 gold.\n");
                playerGold += 50;

                printf("\nYou have reached the end of the dungeon. Congratulations %s!\n", playerName);
                printf("Final Score: %d\n", playerScore);
                printf("Final Gold: %d\n", playerGold);
                printf("Final XP: %d\n", playerXP);
                printf("Final Level: %d\n", playerLevel);
            } else if (strcmp(choice, "Flee") == 0 || strcmp(choice, "flee") == 0) {
                printf("\nYou run away from the monster. You lose some score but are safe for now.\n");
                playerScore -= 5;
            } else {
                printf("\nInvalid choice. Try again.\n");
            }
        } else if (strcmp(choice, "Retreat") == 0 || strcmp(choice, "retreat") == 0) {
            printf("\nYou chicken out and return to the surface. Better luck next time!\n");
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
    } else if (strcmp(choice, "No") == 0 || strcmp(choice, "no") == 0) {
        printf("\nYou decide not to enter the dungeon. Better luck next time!\n");
    } else {
        printf("\nInvalid choice. Try again.\n");
    }

    return 0;
}
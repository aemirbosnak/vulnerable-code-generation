//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 50

// Function Prototypes
void intro();
void choosePath();
void forestPath();
void riverPath();
void deathScreen();
bool playerAlive();

// Main function
int main() {
    intro();
    choosePath();

    return 0;
}

// Introduction to the game
void intro() {
    printf("\nWelcome to the Text-Based Adventure Game!\n\n");
    printf("- You have two paths, one leads to a forest and the other leads to a river.\n");
}

// Allows the player to choose their path
void choosePath() {
    char path[MAX_INPUT_LENGTH];

    printf("Which path do you want to take? (forest / river): ");
    scanf("%s", path);

    if (strcmp(path, "forest") == 0) {
        forestPath();
    } else if (strcmp(path, "river") == 0) {
        riverPath();
    } else {
        printf("Invalid input, please choose a valid path.\n");
        choosePath();
    }
}

// The adventure for the forest path
void forestPath() {
    char action[MAX_INPUT_LENGTH];

    printf("\nYou have entered the forest.\n");
    printf("- You can (1) continue walking or (2) rest.\n");
    printf("Enter your choice: ");
    scanf("%s", action);

    if (strcmp(action, "1") == 0) {
        printf("\nYou come across a clearing with a small cottage.\n");
        printf("- You can (1) go inside or (2) continue walking.\n");
        printf("Enter your choice: ");
        scanf("%s", action);

        if (strcmp(action, "1") == 0) {
            printf("\nAn old woman greets you and gives you a map.\n");
            printf("You continue through the forest with the map in hand.\n");

            // End of adventure
            printf("\nCongrats! You've completed the forest path.\n");
        } else if (strcmp(action, "2") == 0) {
            printf("\nYou continue walking through the forest.\n");
            printf("Unfortunately, you get lost and are unable to find your way out.\n");

            // Player death
            deathScreen();
        } else {
            printf("Invalid input, please choose a valid action.\n");
            forestPath();
        }
    } else if (strcmp(action, "2") == 0) {
        printf("\nYou decide to take a rest.\n");
        printf("While resting, you are ambushed by a group of bandits.\n");

        // Player death
        deathScreen();
    } else {
        printf("Invalid input, please choose a valid action.\n");
        forestPath();
    }
}

// The adventure for the river path
void riverPath() {
    char action[MAX_INPUT_LENGTH];

    printf("\nYou have arrived at the river.\n");
    printf("- You can (1) swim across or (2) build a raft.\n");
    printf("Enter your choice: ");
    scanf("%s", action);

    if (strcmp(action, "1") == 0) {
        printf("\nYou attempt to swim across the river.\n");

        // Player death
        deathScreen();
    } else if (strcmp(action, "2") == 0) {
        printf("\nYou find some wood and build a raft.\n");
        printf("- You can (1) cross the river or (2) explore the river bank.\n");
        printf("Enter your choice: ");
        scanf("%s", action);

        if (strcmp(action, "1") == 0) {
            printf("\nYou safely reach the other side of the river.\n");

            // End of adventure
            printf("\nCongrats! You've completed the river path.\n");
        } else if (strcmp(action, "2") == 0) {
            printf("\nWhile exploring the river bank, you find a hidden treasure.\n");
            printf("You take the treasure and continue on your adventure.\n");

            // End of adventure
            printf("\nCongrats! You've completed the river path.\n");
        } else {
            printf("Invalid input, please choose a valid action.\n");
            riverPath();
        }
    } else {
        printf("Invalid input, please choose a valid action.\n");
        riverPath();
    }
}

// The screen displayed when the player dies
void deathScreen() {
    printf("\nYou died. Game over.\n");
    exit(0);
}

// Checks if the player is still alive
bool playerAlive() {
    // Check if the player is alive
    return true;
}
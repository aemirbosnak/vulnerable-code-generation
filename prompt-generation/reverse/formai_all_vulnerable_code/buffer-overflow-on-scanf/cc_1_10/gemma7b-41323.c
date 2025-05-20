//Gemma-7B DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char name[20];
    int score = 0;
    int level = 1;

    printf("Welcome to the Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Hello, %s, prepare for an adventure!\n", name);

    while (level <= 5) {
        // Display the current level and score
        printf("Level: %d, Score: %d\n", level, score);

        // Choose an adventure
        printf("Choose your adventure:\n");
        printf("1. Fight a dragon\n");
        printf("2. Solve a riddle\n");
        printf("3. Collect a treasure\n");

        // Get the user's choice
        scanf("%d", &choice);

        // Implement the chosen adventure
        switch (choice) {
            case 1:
                score += fightADragon();
                break;
            case 2:
                score += solveRiddle();
                break;
            case 3:
                score += collectTreasure();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Increase the level if the user has completed the current level
        if (score >= level * 10) {
            level++;
        }
    }

    // End the game
    printf("Thank you for playing, %s. Your final score is: %d\n", name, score);

    return 0;
}

int fightADragon() {
    return 20;
}

int solveRiddle() {
    return 15;
}

int collectTreasure() {
    return 10;
}
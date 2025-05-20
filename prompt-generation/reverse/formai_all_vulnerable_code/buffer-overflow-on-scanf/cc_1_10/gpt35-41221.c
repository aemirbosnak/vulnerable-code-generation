//FormAI DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototype
int rollDice(void);

int main(void) {
    int numRolls = 0;
    int currentRoll = 0;
    int totalRolls = 0;
    int rollTotal = 0;
    char answer;

    printf("Welcome to the Dice Roller Game!\n");

    do {
        printf("How many dice would you like to roll? (1-5): ");
        scanf("%d", &numRolls);
        getchar(); // Clear input buffer

        printf("Rolling %d dice...\n\n", numRolls);

        // Loop through and roll the dice
        for (int i = 0; i < numRolls; i++) {
            currentRoll = rollDice();
            printf("Roll %d: %d\n", i+1, currentRoll);
            rollTotal += currentRoll;
            totalRolls++;
        }

        printf("\nTotal Roll: %d\n\n", rollTotal);

        // Ask the user if they want to play again
        printf("Would you like to roll dice again? (y/n): ");
        scanf(" %c", &answer);

        // Reset variables for new roll
        numRolls = 0;
        currentRoll = 0;
        rollTotal = 0;

    } while(answer == 'y' || answer == 'Y');

    printf("\nThanks for playing! Total rolls: %d\n", totalRolls);

    return 0;
}

int rollDice(void) {
    int roll = 0;

    // Seed the random generator
    srand(time(NULL));

    // Generate random dice roll between 1-6
    roll = rand() % 6 + 1;

    return roll;
}
//FormAI DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single dice
int rollDice() {
    int roll = rand() % 6 + 1;
    return roll;
}

// Function to roll specified number of dice
void rollDiceSet(int numDice) {
    int i, roll;

    for (i = 0; i < numDice; i++) {
        roll = rollDice();
        printf("Dice %d:\t%d\n", i+1, roll);
    }
}

int main() {
    int numDice, keepRolling;
    char keepRollingInput;

    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the dice roller!\n");

    do {
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        rollDiceSet(numDice); // Roll the specified number of dice

        // User input to continue rolling or exit program
        do {
            printf("Roll again? (y/n) ");
            scanf(" %c", &keepRollingInput);
        } while (keepRollingInput != 'y' && keepRollingInput != 'n');

        if (keepRollingInput == 'y') {
            keepRolling = 1;
        } else {
            keepRolling = 0;
        }

    } while (keepRolling);

    printf("Thanks for using the dice roller!\n");

    return 0;
}
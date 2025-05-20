//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_SIDES 6

// Function prototypes
void rollDice(int *die1, int *die2);
void displayDice(int die1, int die2);
void displayStatistics(int rolls, int totalSum);

int main() {
    int die1, die2;
    int totalRolls = 0;
    int totalSum = 0;
    char choice;

    // Seed the random number generator
    srand(time(0));

    printf("\nWelcome to the Dice Roller Game!\n");
    printf("===================================\n");

    do {
        // Roll the dice
        rollDice(&die1, &die2);
        displayDice(die1, die2);

        // Update statistics
        totalRolls++;
        totalSum += (die1 + die2);

        // Ask the user if they want to roll again
        printf("\nDo you want to roll again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    // Display final statistics
    printf("\nThank you for playing!\n");
    displayStatistics(totalRolls, totalSum);

    return 0;
}

// Function to roll the dice
void rollDice(int *die1, int *die2) {
    *die1 = (rand() % DICE_SIDES) + 1; // Generate random number between 1 and 6
    *die2 = (rand() % DICE_SIDES) + 1; // Generate random number between 1 and 6
}

// Function to display the rolled dice
void displayDice(int die1, int die2) {
    printf("\nYou rolled: \n");

    // Display the first die
    printf("Die 1: ");
    for (int i = 0; i < die1; i++) {
        printf("*");
    }
    printf(" (%d)\n", die1);

    // Display the second die
    printf("Die 2: ");
    for (int i = 0; i < die2; i++) {
        printf("*");
    }
    printf(" (%d)\n", die2);
}

// Function to display statistics
void displayStatistics(int rolls, int totalSum) {
    if (rolls > 0) {
        printf("===================================\n");
        printf("Total Rolls: %d\n", rolls);
        printf("Total Sum of Rolls: %d\n", totalSum);
        printf("Average Roll: %.2f\n", (double)totalSum / rolls);
        printf("Thank you for rolling the dice!\n");
    } else {
        printf("No rolls were made.\n");
    }
}
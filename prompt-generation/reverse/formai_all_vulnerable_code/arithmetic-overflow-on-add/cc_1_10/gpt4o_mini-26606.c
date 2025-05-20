//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void rollDice(int numberOfDice, int sides);
void displayStatistics(int rolls[], int size);

int main() {
    int numberOfDice, sides;
    char choice;

    // Seed the random number generator
    srand(time(0));

    do {
        // Ask the user for the number of dice and the number of sides
        printf("Welcome to the Dice Roller!\n");
        printf("Enter the number of dice to roll: ");
        scanf("%d", &numberOfDice);
        printf("Enter the number of sides on the dice: ");
        scanf("%d", &sides);

        // Roll the dice
        rollDice(numberOfDice, sides);

        // Ask if the user wants to roll again
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Dice Roller!\n");

    return 0;
}

// Function to roll the dice and display results
void rollDice(int numberOfDice, int sides) {
    int rolls[100]; // Array to store roll results
    int total = 0;

    printf("Rolling %d dice with %d sides...\n", numberOfDice, sides);
    
    for (int i = 0; i < numberOfDice; i++) {
        rolls[i] = (rand() % sides) + 1; // Roll the die
        total += rolls[i]; // Sum the results
        printf("Roll %d: %d\n", i + 1, rolls[i]); // Display each result
    }

    printf("Total: %d\n", total);
    displayStatistics(rolls, numberOfDice);
}

// Function to display the statistics of the rolls
void displayStatistics(int rolls[], int size) {
    int counts[100] = {0}; // To count occurrences of each number
    int maxValue = 0;

    // Determine the highest value rolled
    for (int i = 0; i < size; i++) {
        if (rolls[i] > maxValue) {
            maxValue = rolls[i];
        }
        counts[rolls[i]]++; // Count the occurrence
    }

    printf("Statistics:\n");
    for (int i = 1; i <= maxValue; i++) {
        if (counts[i] > 0) {
            printf("Number %d was rolled %d time(s).\n", i, counts[i]);
        }
    }
}
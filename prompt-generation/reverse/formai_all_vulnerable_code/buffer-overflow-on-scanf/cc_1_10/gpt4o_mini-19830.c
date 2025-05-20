//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_SIDES 6
#define MAX_ROLLS 1000

// Function prototypes
void rollDice(int rolls[], int totalRolls);
void displayResults(int rolls[], int totalRolls);
void calculateProbabilities(int rolls[], int totalRolls);

int main() {
    int totalRolls;
    int rolls[DICE_SIDES] = {0}; // Array to hold counts for each side of the dice

    // Initialization for random number generation
    srand(time(0));

    // User input for number of rolls
    printf("Welcome to the Dice Roller!\n");
    printf("How many times would you like to roll the dice? (max %d)\n", MAX_ROLLS);
    
    // Input validation
    while (1) {
        scanf("%d", &totalRolls);
        if (totalRolls > 0 && totalRolls <= MAX_ROLLS) {
            break;
        } else {
            printf("Please enter a valid number between 1 and %d:\n", MAX_ROLLS);
        }
    }

    // Roll the dice
    rollDice(rolls, totalRolls);

    // Display the results
    displayResults(rolls, totalRolls);

    return 0;
}

// Function to simulate rolling the dice
void rollDice(int rolls[], int totalRolls) {
    for (int i = 0; i < totalRolls; i++) {
        int roll = (rand() % DICE_SIDES) + 1; // Generating a random number between 1 and 6
        rolls[roll - 1]++; // Increment the count for the rolled side
    }
}

// Function to display the results of the dice rolls
void displayResults(int rolls[], int totalRolls) {
    printf("\n--- Dice Roll Results ---\n");
    for (int i = 0; i < DICE_SIDES; i++) {
        printf("Side %d: Count = %d\n", i + 1, rolls[i]);
    }
    calculateProbabilities(rolls, totalRolls);
}

// Function to calculate and display the probability of each side being rolled
void calculateProbabilities(int rolls[], int totalRolls) {
    printf("\n--- Probability of Each Side ---\n");
    for (int i = 0; i < DICE_SIDES; i++) {
        double probability = (double) rolls[i] / totalRolls * 100; // Probability in percentage
        printf("Side %d: Probability = %.2f%%\n", i + 1, probability);
    }

    // Ask the user if they want to roll again
    char choice;
    printf("\nWould you like to roll again? (y/n): ");
    while (1) {
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            main(); // Recursion to restart the rolling process
            return;
        } else if (choice == 'n' || choice == 'N') {
            printf("Thank you for using Dice Roller! Goodbye!\n");
            break;
        } else {
            printf("Please enter 'y' to roll again or 'n' to exit: ");
        }
    }
}
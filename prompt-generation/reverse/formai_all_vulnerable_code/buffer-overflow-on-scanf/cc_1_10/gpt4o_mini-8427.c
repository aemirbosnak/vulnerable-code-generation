//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 100
#define DICE_FACES 6
#define ROLLS_PER_DIE 10

// Function to roll a die n times
void rollDie(int rolls[], int numberOfRolls) {
    for (int i = 0; i < numberOfRolls; i++) {
        rolls[i] = (rand() % DICE_FACES) + 1; // Generate numbers from 1 to DICE_FACES
    }
}

// Function to calculate the frequency of each face from the rolls
void calculateFrequencies(int rolls[], int numberOfRolls, int frequencies[]) {
    for (int i = 0; i < numberOfRolls; i++) {
        frequencies[rolls[i] - 1]++; // Increment the frequency for the rolled number
    }
}

// Function to display the results of the rolls
void displayResults(int rolls[], int numberOfRolls, int frequencies[]) {
    printf("Roll Results:\n");
    for (int i = 0; i < numberOfRolls; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
    
    printf("\nFrequencies of each face:\n");
    for (int i = 0; i < DICE_FACES; i++) {
        printf("Face %d: %d times\n", i + 1, frequencies[i]);
    }
}

// Main function to execute the Dice Roller Program
int main() {
    // Seed the random number generator
    srand(time(NULL));

    int rolls[ROLLS_PER_DIE];
    int frequencies[DICE_FACES] = {0}; // Initialize frequency array

    printf("Welcome to the C Dice Roller Program!\n");
    printf("This program will roll a die %d times and display the results.\n", ROLLS_PER_DIE);

    // Roll the die
    rollDie(rolls, ROLLS_PER_DIE);

    // Calculate the frequencies of the rolled numbers
    calculateFrequencies(rolls, ROLLS_PER_DIE, frequencies);

    // Display the results
    displayResults(rolls, ROLLS_PER_DIE, frequencies);

    // Bonus: Ask the user if they'd like to roll again
    char choice;
    do {
        printf("\nWould you like to roll again? (y/n): ");
        scanf(" %c", &choice); // The space before %c skips any whitespace

        if (choice == 'y' || choice == 'Y') {
            // Reset the frequencies and roll again
            int newRolls[ROLLS_PER_DIE];
            int newFrequencies[DICE_FACES] = {0};

            rollDie(newRolls, ROLLS_PER_DIE);
            calculateFrequencies(newRolls, ROLLS_PER_DIE, newFrequencies);
            displayResults(newRolls, ROLLS_PER_DIE, newFrequencies);
        }

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the C Dice Roller Program!\n");
    return 0;
}
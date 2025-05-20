//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_FACES 20

void rollDice(int numberOfDice, int numberOfFaces);
void displayResults(int *results, int numberOfDice);

int main() {
    int numberOfDice, numberOfFaces;

    // Seed the random number generator
    srand(time(NULL));

    // Introduction to the Dice Roller Program
    printf("Welcome to the C Dice Roller Program!\n");
    printf("You can roll up to %d dice with a maximum of %d faces each.\n", MAX_DICE, MAX_FACES);

    // Get user input for the number of dice and faces
    printf("Enter the number of dice to roll (1 - %d): ", MAX_DICE);
    scanf("%d", &numberOfDice);
    if (numberOfDice < 1 || numberOfDice > MAX_DICE) {
        printf("Invalid number of dice! Please run the program again.\n");
        return 1;
    }

    printf("Enter the number of faces on each die (2 - %d): ", MAX_FACES);
    scanf("%d", &numberOfFaces);
    if (numberOfFaces < 2 || numberOfFaces > MAX_FACES) {
        printf("Invalid number of faces! Please run the program again.\n");
        return 1;
    }

    // Call the function to roll the dice
    rollDice(numberOfDice, numberOfFaces);

    return 0;
}

void rollDice(int numberOfDice, int numberOfFaces) {
    int results[MAX_DICE];
    printf("\nRolling %d dice with %d faces each...\n", numberOfDice, numberOfFaces);

    // Roll the dice and store results
    for (int i = 0; i < numberOfDice; i++) {
        results[i] = (rand() % numberOfFaces) + 1;  // Generate random number from 1 to numberOfFaces
    }

    displayResults(results, numberOfDice);
}

void displayResults(int *results, int numberOfDice) {
    printf("Results of your dice roll:\n");
    for (int i = 0; i < numberOfDice; i++) {
        printf("Die %d: %d\n", i + 1, results[i]);
    }

    // Optionally calculate the total
    int total = 0;
    for (int i = 0; i < numberOfDice; i++) {
        total += results[i];
    }
    printf("Total value rolled: %d\n", total);
}
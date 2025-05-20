//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Express our gratitude for using our dice roller
void expressGratitude() {
    printf("Thank you for choosing our humble dice roller. May your rolls be blessed with fortune and favor.\n\n");
}

// Seed the random number generator with the current time
void seedRandomNumberGenerator() {
    srand(time(NULL));
}

// Roll a single die and return the result
int rollDie(int sides) {
    return (rand() % sides) + 1;
}

// Roll a set of dice and return the sum of the results
int rollDice(int sides, int numDice) {
    int sum = 0;
    for (int i = 0; i < numDice; i++) {
        sum += rollDie(sides);
    }
    return sum;
}

// Print the results of a dice roll
void printResults(int sides, int numDice, int result) {
    printf("You rolled %d %d-sided dice and got a total of %d.\n", numDice, sides, result);
}

// Get the user's input for the number of sides and dice
void getUserInput(int *sides, int *numDice) {
    printf("How many sides do you want each die to have? ");
    scanf("%d", sides);

    printf("How many dice do you want to roll? ");
    scanf("%d", numDice);
}

// Main function
int main() {
    // Express our gratitude
    expressGratitude();

    // Seed the random number generator
    seedRandomNumberGenerator();

    // Get the user's input
    int sides, numDice;
    getUserInput(&sides, &numDice);

    // Roll the dice
    int result = rollDice(sides, numDice);

    // Print the results
    printResults(sides, numDice, result);

    return 0;
}
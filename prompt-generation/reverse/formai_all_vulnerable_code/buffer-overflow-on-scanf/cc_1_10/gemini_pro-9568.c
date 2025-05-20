//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int rollDie() {
    // Initialize random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 6
    int roll = rand() % 6 + 1;

    return roll;
}

// Function to roll multiple dice and print the results
void rollDice(int numDice) {
    // Roll the dice
    int rolls[numDice];
    for (int i = 0; i < numDice; i++) {
        rolls[i] = rollDie();
    }

    // Print the results
    printf("You rolled the following dice:\n");
    for (int i = 0; i < numDice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

// Function to get user input
int getUserInput() {
    int numDice;

    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    return numDice;
}

// Main function
int main() {
    // Get user input
    int numDice = getUserInput();

    // Roll the dice
    rollDice(numDice);

    return 0;
}
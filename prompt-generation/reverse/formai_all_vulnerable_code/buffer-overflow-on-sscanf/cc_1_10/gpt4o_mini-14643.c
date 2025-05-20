//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

// Function prototypes
void displayWelcomeMessage();
int rollDice(int sides);
void playGame();
void displayRollResults(int rolls[], int numRolls, int sides);
void getInput(int *numDice, int *sides);

int main() {
    srand(time(NULL)); // Seed for random number generation
    displayWelcomeMessage();
    playGame();
    return 0;
}

// Function to display a welcome message
void displayWelcomeMessage() {
    printf("===================================\n");
    printf("         Welcome to Dice Roller    \n");
    printf("===================================\n");
    printf("Roll up to %d dice with any number of sides!\n", MAX_DICE);
    printf("Type 'q' to quit at any time.\n");
}

// Function to roll a dice of a given number of sides
int rollDice(int sides) {
    return (rand() % sides) + 1; // Returns a random number between 1 and sides
}

// Function to play the dice game
void playGame() {
    int numDice, sides;
    char input[10];

    while (1) {
        getInput(&numDice, &sides);
        if (numDice == -1 || sides == -1) {
            break; // Exit the loop if the user wants to quit
        }

        if (numDice > MAX_DICE || numDice <= 0 || sides <= 0) {
            printf("Invalid input! Please enter a valid number of dice and sides.\n\n");
            continue;
        }

        int rolls[numDice];
        for (int i = 0; i < numDice; i++) {
            rolls[i] = rollDice(sides);
        }

        displayRollResults(rolls, numDice, sides);
    }

    printf("Thank you for playing! Goodbye!\n");
}

// Function to display the results of the rolls
void displayRollResults(int rolls[], int numRolls, int sides) {
    printf("You rolled %d dice with %d sides:\n", numRolls, sides);
    for (int i = 0; i < numRolls; i++) {
        printf("Dice %d: %d\n", i + 1, rolls[i]);
    }
    printf("===================================\n");
}

// Function to get input for the number of dice and sides
void getInput(int *numDice, int *sides) {
    printf("Enter number of dice (1-%d) and sides (>0): ", MAX_DICE);
    char buffer[20];
    fgets(buffer, sizeof(buffer), stdin);

    // Check for quit command
    if (buffer[0] == 'q' || buffer[0] == 'Q') {
        *numDice = -1;
        *sides = -1;
        return;
    }

    // Parse input
    if (sscanf(buffer, "%d %d", numDice, sides) != 2) {
        printf("Invalid input format! Please enter two integers.\n");
        *numDice = 0;
        *sides = 0;
        return;
    }
}

// Function to display goodbye message (If needed)
void displayGoodbyeMessage() {
    printf("Exiting the Dice Roller Program!\n");
}
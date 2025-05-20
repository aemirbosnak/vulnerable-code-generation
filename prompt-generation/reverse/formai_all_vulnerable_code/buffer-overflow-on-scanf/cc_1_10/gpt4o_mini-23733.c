//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

// Function to roll a single die with `sides` number of sides
int rollDice(int sides) {
    return (rand() % sides) + 1;
}

// Function to roll multiple dice of the same type
void rollMultipleDice(int numDice, int sides) {
    int total = 0;
    printf("Rolling %d %d-sided dice:\n", numDice, sides);
    
    for (int i = 0; i < numDice; i++) {
        int result = rollDice(sides);
        total += result;
        printf("Die %d: %d\n", i + 1, result);
    }
    
    printf("Total: %d\n", total);
}

// Function to display options for rolling dice
void displayMenu() {
    printf("Welcome to the Dice Roller!\n");
    printf("Select the number of dice to roll (1-%d): ", MAX_DICE);
}

// Function to get a valid integer input
int getValidInput() {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1 || input < 1 || input > MAX_DICE) {
            printf("Invalid input. Please enter a number between 1 and %d: ", MAX_DICE);
            while (getchar() != '\n'); // clear input buffer
        } else {
            break;
        }
    }
    return input;
}

// Function to get the number of sides for the dice
int getDiceSides() {
    int sides;
    while (1) {
        printf("Enter the number of sides for the dice (1-%d): ", MAX_SIDES);
        if (scanf("%d", &sides) != 1 || sides < 1 || sides > MAX_SIDES) {
            printf("Invalid input. Please enter a number between 1 and %d: ", MAX_SIDES);
            while (getchar() != '\n'); // clear input buffer
        } else {
            break;
        }
    }
    return sides;
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    int numDice, sides;
    char playAgain;

    do {
        displayMenu();
        numDice = getValidInput();
        sides = getDiceSides();
        rollMultipleDice(numDice, sides);

        printf("Would you like to roll again? (y/n): ");
        while (getchar() != '\n'); // clear input buffer 
        playAgain = getchar();

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for using the Dice Roller! Goodbye.\n");
    return 0;
}
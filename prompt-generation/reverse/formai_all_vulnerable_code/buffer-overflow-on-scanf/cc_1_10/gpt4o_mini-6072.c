//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 20

// Function prototypes
void displayMenu();
int rollDice(int sides);
void clearInputBuffer();
void handleRoll(int sides);
void getUserInput(int *sides);

int main() {
    int diceSides = 0;
    char choice;

    // Seed for random number generation
    srand(time(NULL));

    // Main Loop
    do {
        displayMenu();
        printf("Enter your choice (r = roll, q = quit): ");
        choice = getchar();
        clearInputBuffer(); // Clear newline character from input buffer

        switch (choice) {
            case 'r':
                getUserInput(&diceSides);
                if (diceSides < 1 || diceSides > MAX_SIDES) {
                    printf("Please enter a valid number of sides (1 to %d).\n", MAX_SIDES);
                } else {
                    handleRoll(diceSides);
                }
                break;
            case 'q':
                printf("Thank you for using the Dice Roller! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'q');

    return 0;
}

// Displays the menu options
void displayMenu() {
    printf("\n======== Dice Roller ========\n");
    printf("Options:\n");
    printf("r - Roll a dice\n");
    printf("q - Quit\n");
    printf("==============================\n");
}

// Rolls a dice with the given number of sides
int rollDice(int sides) {
    return (rand() % sides) + 1; // Generate a random number between 1 and sides
}

// Clears the input buffer to avoid newline issues
void clearInputBuffer() {
    while (getchar() != '\n'); // Consume characters in the input buffer
}

// Handles the rolling of the dice and outputts the result
void handleRoll(int sides) {
    int result = rollDice(sides);
    printf("You rolled a %d (on a %d-sided die).\n", result, sides);
}

// Asks the user for number of sides on the dice
void getUserInput(int *sides) {
    printf("Enter the number of sides for the dice (1 - %d): ", MAX_SIDES);
    if (scanf("%d", sides) != 1) {
        clearInputBuffer(); // Clear invalid input
        *sides = 0; // Reset sides to invalid
    } else {
        clearInputBuffer(); // Clear the input buffer after valid input
    }
}
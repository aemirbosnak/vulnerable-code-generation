//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice(int sides) {
    return (rand() % sides) + 1;
}

// Function to display the results of the rolls
void displayResults(int* rolls, int numberOfRolls, int sides) {
    printf("You've rolled %d dice with %d sides:\n", numberOfRolls, sides);
    for (int i = 0; i < numberOfRolls; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
}

// Function to get a valid number of sides for the dice
int getValidSides() {
    int sides;
    while (1) {
        printf("Enter the number of sides for the dice (greater than 0): ");
        if (scanf("%d", &sides) != 1 || sides <= 0) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n'); // clear the input buffer
        } else {
            break;
        }
    }
    return sides;
}

// Function to get a valid number of rolls
int getValidRolls() {
    int rolls;
    while (1) {
        printf("Enter the number of times to roll the dice (greater than 0): ");
        if (scanf("%d", &rolls) != 1 || rolls <= 0) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n'); // clear the input buffer
        } else {
            break;
        }
    }
    return rolls;
}

// Function to ask user if they want to roll again
int askToRollAgain() {
    char choice;
    while (1) {
        printf("Do you want to roll again? (y/n): ");
        if (scanf(" %c", &choice) == 1 && (choice == 'y' || choice == 'n')) {
            return (choice == 'y') ? 1 : 0;
        } else {
            printf("Invalid choice. Please enter 'y' or 'n'.\n");
            while (getchar() != '\n'); // clear the input buffer
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    int sides, numberOfRolls, rollAgain;

    do {
        // Get valid number of sides and rolls from the user
        sides = getValidSides();
        numberOfRolls = getValidRolls();

        // Create an array to store the rolls
        int* rolls = malloc(numberOfRolls * sizeof(int));
        if (rolls == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        // Roll the dice
        for (int i = 0; i < numberOfRolls; i++) {
            rolls[i] = rollDice(sides);
        }

        // Display the results
        displayResults(rolls, numberOfRolls, sides);

        // Free the allocated memory
        free(rolls);

        // Ask user if they want to roll again
        rollAgain = askToRollAgain();
    } while (rollAgain);

    printf("Thank you for using the dice roller!\n");
    return 0;
}
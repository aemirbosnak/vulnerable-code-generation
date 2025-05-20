//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die with a given number of sides
int rollDie(int sides) {
    return (rand() % sides) + 1; // Random number between 1 and 'sides'
}

// Function to roll multiple dice
void rollDice(int numberOfDice, int sides) {
    int total = 0; // Initialize total value
    printf("Rolling %d %d-sided dice:\n", numberOfDice, sides);
    for (int i = 0; i < numberOfDice; i++) {
        int result = rollDie(sides);
        total += result; // Add individual roll to total
        printf("Die %d: %d\n", i + 1, result);
    }
    printf("Total: %d\n", total); // Print the total of all rolls
}

// Function to display the menu and get user input
void displayMenu() {
    printf("\nWelcome to the Dice Roller!\n");
    printf("1: Roll Dice\n");
    printf("2: Exit\n");
}

// Main function
int main() {
    srand(time(0)); // Seed random number generator with current time
    int option;
    do {
        displayMenu(); // Show the menu
        printf("Please select an option: ");
        scanf("%d", &option);

        // Check if the user wants to roll dice
        if (option == 1) {
            int numberOfDice, sides;
            printf("Enter the number of dice: ");
            scanf("%d", &numberOfDice);
            printf("Enter the number of sides on each die: ");
            scanf("%d", &sides);

            // Validate user input
            if (numberOfDice <= 0 || sides <= 0) {
                printf("Error: The number of dice and sides must be positive integers.\n");
                continue;
            }

            rollDice(numberOfDice, sides); // Roll the dice
        } else if (option != 2) {
            printf("Error: Invalid option! Please select again.\n");
        }
    } while (option != 2); // Repeat until the user decides to exit

    printf("Thank you for using the Dice Roller. Goodbye!\n");
    return 0; // Exit the program
}
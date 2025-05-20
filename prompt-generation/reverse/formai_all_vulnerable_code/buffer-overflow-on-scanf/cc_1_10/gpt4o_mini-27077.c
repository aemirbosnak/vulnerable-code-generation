//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice and return the result
int rollDice() {
    return (rand() % 6) + 1; // returns a number between 1 and 6
}

// Function to simulate multiple dice rolls
void rollMultipleDice(int numRolls) {
    if (numRolls <= 0) {
        printf("Number of rolls must be greater than 0.\n");
        return;
    }

    int total = 0;
    printf("Rolling the dice %d times:\n", numRolls);
    
    for (int i = 0; i < numRolls; i++) {
        int result = rollDice();
        printf("Roll %d: %d\n", i + 1, result);
        total += result;
    }
    
    printf("Total sum of rolls: %d\n", total);
}

// Function to simulate a user choosing dice to roll
void chooseRolls() {
    int numRolls = 0;
    printf("Welcome to the Dice Roller!\n");
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);
    
    rollMultipleDice(numRolls);
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Dice Roller Menu ===\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("========================\n");
}

// The main logic of the program
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    int choice;

    do {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                chooseRolls();
                break;
            case 2:
                printf("Exiting the Dice Roller. Have a great day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 2);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIDES 6
#define MAX_DICE 5

// Function to display the menu options
void displayMenu() {
    printf("Welcome to the Dice Roller Program!\n");
    printf("Please select an option:\n");
    printf("1. Roll a single die\n");
    printf("2. Roll multiple dice\n");
    printf("3. Quit the program\n");
}

// Function to roll a single die
int rollSingleDie() {
    return (rand() % NUM_SIDES) + 1;
}

// Function to roll multiple dice
void rollMultipleDice(int numDice) {
    printf("Rolling %d dice...\n", numDice);
    for (int i = 0; i < numDice; i++) {
        printf("Die %d: %d\n", i + 1, rollSingleDie());
    }
}

// Function to handle the user's choice for rolling dice
void handleUserChoice(int choice) {
    int numDice;
    switch (choice) {
        case 1:
            printf("You chose to roll a single die.\n");
            printf("You rolled: %d\n", rollSingleDie());
            break;
        case 2:
            printf("Enter the number of dice to roll (1 to %d): ", MAX_DICE);
            scanf("%d", &numDice);
            if (numDice < 1 || numDice > MAX_DICE) {
                printf("Invalid number of dice! Please choose between 1 and %d.\n", MAX_DICE);
            } else {
                rollMultipleDice(numDice);
            }
            break;
        case 3:
            printf("Thank you for using the Dice Roller Program. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
            break;
    }
}

// Main function
int main() {
    int choice;

    // Seed the random number generator
    srand(time(NULL));

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handleUserChoice(choice);
        printf("\n");
    }

    return 0;
}
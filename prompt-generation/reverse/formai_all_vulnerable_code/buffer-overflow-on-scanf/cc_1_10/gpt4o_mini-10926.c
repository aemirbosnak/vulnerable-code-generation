//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 5
#define MAX_SIDES 6
#define ROLLS_LIMIT 100

// Function to display the menu
void displayMenu() {
    printf("\n-------------------------------------\n");
    printf("         Dice Roller Menu            \n");
    printf("-------------------------------------\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("-------------------------------------\n");
    printf("Select an option: ");
}

// Function to roll the dice
void rollDice(int numDice, int *results) {
    for (int i = 0; i < numDice; i++) {
        results[i] = (rand() % MAX_SIDES) + 1;  // Roll a die
    }
}

// Function to display the results
void displayResults(int numDice, int *results) {
    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

// Main functionality of the Dice Roller
int main() {
    int choice, numDice, results[MAX_DICE];
    srand(time(NULL));  // Seed for random number generation

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of dice to roll (1 to %d): ", MAX_DICE);
                scanf("%d", &numDice);

                if (numDice < 1 || numDice > MAX_DICE) {
                    printf("Invalid number of dice! Please choose between 1 and %d.\n", MAX_DICE);
                } else {
                    rollDice(numDice, results);
                    displayResults(numDice, results);
                }
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 2);

    return 0;
}
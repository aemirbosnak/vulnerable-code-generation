//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void rollDice(int numDice, int sides) {
    int total = 0;
    int rolls[MAX_DICE] = {0};
    
    if (numDice < 1 || numDice > MAX_DICE) {
        fprintf(stderr, "Error: Number of dice must be between 1 and %d.\n", MAX_DICE);
        return;
    }
   
    if (sides < 2 || sides > MAX_SIDES) {
        fprintf(stderr, "Error: Number of sides must be between 2 and %d.\n", MAX_SIDES);
        return;
    }

    printf("Rolling %d dice with %d sides each:\n", numDice, sides);
    
    for (int i = 0; i < numDice; i++) {
        rolls[i] = (rand() % sides) + 1; // Roll the dice
        total += rolls[i];
        printf("Dice %d: %d\n", i + 1, rolls[i]);
    }
    
    printf("Total: %d\n", total);
}

void displayMenu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("------------------------\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice;
    
    do {
        displayMenu();
        printf("Please select an option: ");
        int result = scanf("%d", &choice);
        if (result != 1) {
            // Clear the invalid input from stdin
            while (getchar() != '\n');
            choice = 0; // Reset choice
        }
        
        if (choice == 1) {
            int numDice, sides;
            printf("Enter number of dice (1 to %d): ", MAX_DICE);
            scanf("%d", &numDice);
            printf("Enter number of sides on each die (2 to %d): ", MAX_SIDES);
            scanf("%d", &sides);
            rollDice(numDice, sides);
        } else if (choice != 2) {
            printf("Invalid option. Please try again.\n");
        }
        
    } while (choice != 2);
    
    printf("Thank you for using the Dice Roller! Goodbye!\n");
    
    return 0;
}
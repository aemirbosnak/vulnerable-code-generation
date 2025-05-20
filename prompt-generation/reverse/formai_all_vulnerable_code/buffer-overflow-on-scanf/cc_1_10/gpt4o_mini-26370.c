//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die with a specified number of sides
int rollDie(int sides) {
    return (rand() % sides) + 1;
}

// Function to roll multiple dice and return the results
void rollMultipleDice(int numDice, int sides, int results[]) {
    for (int i = 0; i < numDice; i++) {
        results[i] = rollDie(sides);
    }
}

// Function to print the results of the dice rolls
void printResults(int numDice, int results[], int total) {
    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        if (i > 0) printf(", ");
        printf("%d", results[i]);
    }
    printf("\nTotal: %d\n", total);
}

// Function to display a menu for the user
void displayMenu() {
    printf("Welcome to the Dice Roller!\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("Please select an option: ");
}

// Function to handle rolling the dice based on user input
void rollDice() {
    int numDice, sides;
    printf("Enter number of dice: ");
    scanf("%d", &numDice);
    
    printf("Enter number of sides for each die: ");
    scanf("%d", &sides);
    
    // Validate input
    if (numDice <= 0 || sides <= 0) {
        printf("Invalid input. Number of dice and sides must be greater than zero.\n");
        return;
    }

    int* results = (int*)malloc(numDice * sizeof(int));
    if (!results) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    rollMultipleDice(numDice, sides, results);
    
    // Calculate total
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        total += results[i];
    }

    printResults(numDice, results, total);
    free(results);
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                rollDice();
                break;
            case 2:
                printf("Thank you for using the Dice Roller! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 2);

    return 0;
}
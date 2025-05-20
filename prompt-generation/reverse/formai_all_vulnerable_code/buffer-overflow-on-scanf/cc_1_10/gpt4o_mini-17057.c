//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void clearBuffer() {
    while (getchar() != '\n');
}

void rollDice(int numDice, int sides) {
    if(numDice < 1 || numDice > MAX_DICE || sides < 1 || sides > MAX_SIDES) {
        printf("Invalid input. Number of dice must be between 1 and %d, and sides must be between 1 and %d.\n", MAX_DICE, MAX_SIDES);
        return;
    }

    printf("Rolling %d dice with %d sides:\n", numDice, sides);
    int total = 0;

    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % sides) + 1; // Random roll
        printf("Dice %d: %d\n", i + 1, roll);
        total += roll;
    }

    printf("Total roll: %d\n", total);
}

void displayMenu() {
    printf("\n=== Welcome to the C Dice Roller ===\n");
    printf("1. Roll the dice\n");
    printf("2. Exit\n");
    printf("=====================================\n");
    printf("Choose an option: ");
}

int main() {
    // Seed the random number generator
    srand(time(0));
    int option;
    
    do {
        displayMenu();
        while (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a valid option.\n");
            clearBuffer();
        }
        clearBuffer();

        if (option == 1) {
            int numDice, sides;

            printf("Enter number of dice (1-%d): ", MAX_DICE);
            while (scanf("%d", &numDice) != 1) {
                printf("Invalid input. Please enter a valid number of dice.\n");
                clearBuffer();
            }
            clearBuffer();

            printf("Enter number of sides on each die (1-%d): ", MAX_SIDES);
            while (scanf("%d", &sides) != 1) {
                printf("Invalid input. Please enter a valid number of sides.\n");
                clearBuffer();
            }
            clearBuffer();

            rollDice(numDice, sides);
        } else if (option != 2) {
            printf("Exiting. Please select a valid option.\n");
        }
    } while (option != 2);

    printf("Thank you for using the C Dice Roller! Goodbye!\n");
    return 0;
}
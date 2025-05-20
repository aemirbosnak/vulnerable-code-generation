//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int numDice, int sides) {
    int total = 0;
    printf("Rolling %d %d-sided dice...\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % sides) + 1; // Generate random number between 1 and sides
        printf("Roll %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n\n", total);
}

void printMenu() {
    printf("Welcome to the C Dice Roller!\n");
    printf("Please choose an option:\n");
    printf("1. Roll a 6-sided die\n");
    printf("2. Roll a 10-sided die\n");
    printf("3. Roll a 20-sided die\n");
    printf("4. Roll custom dice\n");
    printf("5. Exit\n");
}

int main() {
    int choice, numDice, sides;

    // Seed random number generator
    srand(time(NULL));

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many dice do you want to roll? ");
                scanf("%d", &numDice);
                rollDice(numDice, 6);
                break;

            case 2:
                printf("How many dice do you want to roll? ");
                scanf("%d", &numDice);
                rollDice(numDice, 10);
                break;

            case 3:
                printf("How many dice do you want to roll? ");
                scanf("%d", &numDice);
                rollDice(numDice, 20);
                break;

            case 4:
                printf("Enter the number of dice: ");
                scanf("%d", &numDice);
                printf("Enter the number of sides on each die: ");
                scanf("%d", &sides);
                rollDice(numDice, sides);
                break;

            case 5:
                printf("Thank you for using the C Dice Roller! Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
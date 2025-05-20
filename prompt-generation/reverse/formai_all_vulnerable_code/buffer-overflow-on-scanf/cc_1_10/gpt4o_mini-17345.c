//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printDiceRoll(int sides, int roll) {
    printf("You rolled a %d on a %d-sided die!\n", roll, sides);
}

int rollDice(int sides) {
    return (rand() % sides) + 1; // Random number between 1 and sides
}

void displayMenu() {
    printf("\n=== Dice Roller ===\n");
    printf("1. Roll a Die\n");
    printf("2. Roll Multiple Dice\n");
    printf("3. Exit\n");
    printf("====================\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice, sides, numOfDice, roll;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number.\n");
            while(getchar() != '\n'); // Clear the buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter the number of sides on the die (e.g. 6 for a standard die): ");
                if (scanf("%d", &sides) != 1 || sides < 1) {
                    printf("Invalid input. The number of sides must be a positive integer.\n");
                    while(getchar() != '\n');
                    break;
                }
                roll = rollDice(sides);
                printDiceRoll(sides, roll);
                break;

            case 2:
                printf("Enter the number of sides on the die: ");
                if (scanf("%d", &sides) != 1 || sides < 1) {
                    printf("Invalid input. The number of sides must be a positive integer.\n");
                    while(getchar() != '\n');
                    break;
                }
                printf("Enter the number of dice to roll: ");
                if (scanf("%d", &numOfDice) != 1 || numOfDice < 1) {
                    printf("Invalid input. The number of dice must be a positive integer.\n");
                    while(getchar() != '\n');
                    break;
                }
                
                printf("Rolling %d %d-sided dice:\n", numOfDice, sides);
                for (int i = 0; i < numOfDice; i++) {
                    roll = rollDice(sides);
                    printDiceRoll(sides, roll);
                }
                break;

            case 3:
                printf("Thank you for using the Dice Roller! Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
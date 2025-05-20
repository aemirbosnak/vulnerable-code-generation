//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMenu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("------------------------\n");
    printf("Please select an option (1 or 2): ");
}

int rollDice(int numDice) {
    int total = 0;
    printf("Rolling %d dice...\n", numDice);
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % 6) + 1; // Generate a number between 1 and 6
        printf("Die %d: %d\n", i + 1, roll);
        total += roll;
    }
    return total;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int option;
    int numDice;

    printf("Welcome to the Dice Roller!\n");
    
    do {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("How many dice would you like to roll (1-5)? ");
                scanf("%d", &numDice);

                if (numDice < 1 || numDice > 5) {
                    printf("Please enter a valid number of dice (between 1 and 5).\n");
                } else {
                    int result = rollDice(numDice);
                    printf("Total result of rolls: %d\n", result);
                }
                break;

            case 2:
                printf("Thank you for using the Dice Roller! Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    } while (option != 2);

    return 0;
}
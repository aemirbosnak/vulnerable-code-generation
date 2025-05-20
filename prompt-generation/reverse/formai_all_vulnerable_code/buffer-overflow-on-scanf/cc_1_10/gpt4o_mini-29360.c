//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void printInstructions() {
    printf("Welcome to the Dice Roller!\n");
    printf("You can roll multiple dice of configurable sides.\n");
    printf("Commands:\n");
    printf("1 - Roll Dice\n");
    printf("2 - Change Configuration\n");
    printf("3 - Exit\n");
}

void getConfiguration(int *numDice, int *numSides) {
    printf("Enter the number of dice (1 to %d): ", MAX_DICE);
    scanf("%d", numDice);
    if (*numDice < 1 || *numDice > MAX_DICE) {
        printf("Invalid number of dice. Setting to 1.\n");
        *numDice = 1;
    }

    printf("Enter the number of sides on each die (1 to %d): ", MAX_SIDES);
    scanf("%d", numSides);
    if (*numSides < 1 || *numSides > MAX_SIDES) {
        printf("Invalid number of sides. Setting to 6.\n");
        *numSides = 6;
    }
}

void rollDice(int numDice, int numSides) {
    int total = 0;
    printf("Rolling %d dice with %d sides:\n", numDice, numSides);
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % numSides) + 1;
        printf("Die %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int numDice = 1, numSides = 6;
    int choice;

    while (1) {
        printInstructions();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rollDice(numDice, numSides);
                break;
            case 2:
                getConfiguration(&numDice, &numSides);
                break;
            case 3:
                printf("Exiting the Dice Roller. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
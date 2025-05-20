//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void rollDice(int numDice, int sides) {
    printf("Rolling %d dice with %d sides...\n", numDice, sides);
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % sides) + 1;
        printf("Roll %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

void showMenu() {
    printf("\n---------- Dice Roller ----------\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("--------------------------------\n");
    printf("Select an option: ");
}

void getDiceInput(int *numDice, int *sides) {
    printf("Enter number of dice (1-%d): ", MAX_DICE);
    scanf("%d", numDice);
    if (*numDice < 1 || *numDice > MAX_DICE) {
        printf("Invalid number of dice. Defaulting to 1.\n");
        *numDice = 1;
    }

    printf("Enter number of sides (1-%d): ", MAX_SIDES);
    scanf("%d", sides);
    if (*sides < 1 || *sides > MAX_SIDES) {
        printf("Invalid number of sides. Defaulting to 6.\n");
        *sides = 6;
    }
}

void displayGoodbyeMessage() {
    printf("Thank you for playing the Dice Roller!\n");
    printf("May your rolls always favor you!\n");
}

int main() {
    srand(time(NULL));
    int choice;
    int numDice, sides;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getDiceInput(&numDice, &sides);
                rollDice(numDice, sides);
                break;

            case 2:
                displayGoodbyeMessage();
                return 0;

            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 6
#define MIN_DICE 1

void printDiceRoll(int diceValue) {
    switch (diceValue) {
        case 1:
            printf("-------\n");
            printf("|     |\n");
            printf("|  *  |\n");
            printf("|     |\n");
            printf("-------\n");
            break;
        case 2:
            printf("-------\n");
            printf("| *   |\n");
            printf("|     |\n");
            printf("|   * |\n");
            printf("-------\n");
            break;
        case 3:
            printf("-------\n");
            printf("| *   |\n");
            printf("|  *  |\n");
            printf("|   * |\n");
            printf("-------\n");
            break;
        case 4:
            printf("-------\n");
            printf("| * * |\n");
            printf("|     |\n");
            printf("| * * |\n");
            printf("-------\n");
            break;
        case 5:
            printf("-------\n");
            printf("| * * |\n");
            printf("|  *  |\n");
            printf("| * * |\n");
            printf("-------\n");
            break;
        case 6:
            printf("-------\n");
            printf("| * * |\n");
            printf("| * * |\n");
            printf("| * * |\n");
            printf("-------\n");
            break;
        default:
            printf("Invalid Dice Value\n");
    }
}

int rollDice() {
    return (rand() % MAX_DICE) + 1;
}

void rollMultipleDice(int numberOfDice) {
    printf("Rolling %d dice:\n", numberOfDice);
    for (int i = 0; i < numberOfDice; i++) {
        int diceValue = rollDice();
        printf("Dice %d: ", i + 1);
        printDiceRoll(diceValue);
    }
}

int main() {
    srand(time(NULL)); // Initialize random number generator

    int numberOfDice;

    printf("Welcome to the Linux Dice Roller!\n");
    while (1) {
        printf("Enter the number of dice to roll (1 to 5) or 0 to exit: ");
        scanf("%d", &numberOfDice);

        if (numberOfDice == 0) {
            printf("Exiting the Dice Roller. Goodbye!\n");
            break;
        }

        if (numberOfDice < 1 || numberOfDice > 5) {
            printf("Please enter a valid number of dice between 1 and 5.\n");
            continue;
        }

        rollMultipleDice(numberOfDice);
    }

    return 0;
}
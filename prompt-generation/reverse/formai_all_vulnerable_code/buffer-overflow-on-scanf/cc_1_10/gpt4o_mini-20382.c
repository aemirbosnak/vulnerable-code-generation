//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

void printInstructions() {
    printf("Welcome to the Multi-Dice Roller!\n");
    printf("You can roll up to %d dice at once.\n", MAX_DICE);
    printf("You can specify the number of sides for each die.\n");
    printf("For example, to roll 3 six-sided dice, input: 3 6\n");
    printf("To exit the program, simply enter '0'.\n");
    printf("\n");
}

void rollDice(int numDice, int sides) {
    int total = 0;
    printf("Rolling %d %d-sided dice...\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % sides) + 1;
        printf("Die %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n\n", total);
}

int main() {
    int numDice, sides;

    // Initialize random seed
    srand(time(NULL));
    
    printInstructions();

    while (1) {
        printf("Enter the number of dice and the number of sides (e.g., 3 6): ");
        int inputs = scanf("%d %d", &numDice, &sides);

        // Check for invalid input or exit condition
        if (inputs != 2 || numDice < 0) {
            break;  // Exit condition
        }
        if (numDice > MAX_DICE) {
            printf("You can only roll up to %d dice at once.\n\n", MAX_DICE);
            continue;
        }
        if (sides <= 1) {
            printf("The number of sides must be greater than 1!\n\n");
            continue;
        }

        rollDice(numDice, sides);
    }

    printf("Thank you for using the Multi-Dice Roller! Goodbye!\n");
    return 0;
}
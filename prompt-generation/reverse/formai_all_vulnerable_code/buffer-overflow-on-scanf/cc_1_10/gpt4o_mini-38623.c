//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 5
#define MAX_SIDES 20

void printInstructions() {
    printf("Welcome to the C Dice Roller!\n");
    printf("You can roll up to %d dice, with a maximum of %d sides each.\n", MAX_DICE, MAX_SIDES);
    printf("Enter the number of sides for the dice and the number of dice you want to roll.\n");
    printf("To exit the program, enter '0' when prompted for the number of dice.\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void rollMultipleDice(int numDice, int sides) {
    printf("Rolling %d dice with %d sides each...\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        int roll = rollDice(sides);
        printf("Dice %d: %d\n", i + 1, roll);
    }
}

int main() {
    int numDice, numSides;

    // Seed the random number generator
    srand(time(0));

    printInstructions();

    while (1) {
        printf("Enter number of sides (2 to %d) for the dice or 0 to exit: ", MAX_SIDES);
        scanf("%d", &numSides);
        if (numSides == 0) {
            printf("Exiting the program. Thanks for playing!\n");
            break;
        }
        
        if (numSides < 2 || numSides > MAX_SIDES) {
            printf("Invalid number of sides. Please try again.\n");
            continue;
        }

        printf("Enter the number of dice you want to roll (1 to %d): ", MAX_DICE);
        scanf("%d", &numDice);
        if (numDice < 1 || numDice > MAX_DICE) {
            printf("Invalid number of dice. Please try again.\n");
            continue;
        }

        rollMultipleDice(numDice, numSides);
    }

    return 0;
}
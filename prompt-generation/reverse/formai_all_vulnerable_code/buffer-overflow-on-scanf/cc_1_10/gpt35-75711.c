//FormAI DATASET v1.0 Category: Dice Roller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i;
    char ch;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of dice and number of sides per die from the user
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);

    printf("How many sides does each die have? ");
    scanf("%d", &numSides);

    // Check that the number of dice and number of sides are valid
    if (numDice <= 0 || numSides <= 0) {
        printf("Invalid number of dice or number of sides.\n");
        return 1;
    }

    // Roll the dice and print the results
    printf("Rolling %d %d-sided dice...\n", numDice, numSides);
    for (i = 0; i < numDice; i++) {
        printf("Die %d: %d\n", i + 1, rand() % numSides + 1);
    }

    // Prompt the user to roll again
    printf("Roll again? (y/n) ");
    scanf(" %c", &ch);

    while (ch == 'y' || ch == 'Y') {
        // Get the number of dice and number of sides per die from the user
        printf("\nHow many dice do you want to roll? ");
        scanf("%d", &numDice);

        printf("How many sides does each die have? ");
        scanf("%d", &numSides);

        // Check that the number of dice and number of sides are valid
        if (numDice <= 0 || numSides <= 0) {
            printf("Invalid number of dice or number of sides.\n");
            return 1;
        }

        // Roll the dice and print the results
        printf("\nRolling %d %d-sided dice...\n", numDice, numSides);
        for (i = 0; i < numDice; i++) {
            printf("Die %d: %d\n", i + 1, rand() % numSides + 1);
        }

        // Prompt the user to roll again
        printf("\nRoll again? (y/n) ");
        scanf(" %c", &ch);

    }

    printf("Thanks for playing!\n");

    return 0;
}
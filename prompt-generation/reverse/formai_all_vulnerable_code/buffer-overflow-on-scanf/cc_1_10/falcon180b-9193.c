//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100

int rollDice(int numSides, int numDice) {
    int i, j, total = 0;
    for (i = 0; i < numDice; i++) {
        for (j = 0; j < numSides; j++) {
            total += rand() % numSides + 1;
        }
    }
    return total;
}

int main() {
    int numSides, numDice, i, j, total;
    char playAgain;

    srand(time(NULL));

    do {
        printf("Enter the number of sides for the dice: ");
        scanf("%d", &numSides);
        if (numSides <= 0 || numSides > MAX_SIDES) {
            printf("Invalid number of sides.\n");
            continue;
        }

        printf("Enter the number of dice to roll: ");
        scanf("%d", &numDice);
        if (numDice <= 0 || numDice > MAX_DICE) {
            printf("Invalid number of dice.\n");
            continue;
        }

        total = rollDice(numSides, numDice);

        printf("You rolled %d dice with %d sides each.\n", numDice, numSides);
        printf("The total is: %d\n", total);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
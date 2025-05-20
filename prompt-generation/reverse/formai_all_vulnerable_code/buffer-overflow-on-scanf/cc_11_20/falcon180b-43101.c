//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIDES 6

int main() {
    int numDice, numSides, i, j, total;
    int diceValues[NUM_SIDES];
    char playAgain;

    do {
        printf("Enter number of dice: ");
        scanf("%d", &numDice);

        if (numDice <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numDice <= 0);

    do {
        printf("Enter number of sides per dice: ");
        scanf("%d", &numSides);

        if (numSides <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numSides <= 0);

    srand(time(NULL));

    for (i = 0; i < numDice; i++) {
        for (j = 0; j < numSides; j++) {
            diceValues[j] = rand() % numSides + 1;
        }
        printf("Dice %d: ", i + 1);
        for (j = 0; j < numSides; j++) {
            printf("%d ", diceValues[j]);
        }
        printf("\n");
        total += diceValues[0];
    }

    printf("Total: %d\n\n", total);

    do {
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain!= 'y' && playAgain!= 'n');

    if (playAgain == 'y') {
        main();
    }

    return 0;
}
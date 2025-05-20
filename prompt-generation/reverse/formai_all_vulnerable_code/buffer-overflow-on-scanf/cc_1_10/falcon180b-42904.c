//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, total = 0;
    char playAgain;

    srand(time(NULL));

    do {
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);

        if (numDice <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numDice <= 0);

    do {
        printf("How many sides do the dice have? ");
        scanf("%d", &numSides);

        if (numSides <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numSides <= 0);

    int dice[numDice];

    for (i = 0; i < numDice; i++) {
        dice[i] = rand() % numSides + 1;
        total += dice[i];
    }

    printf("You rolled %d dice with %d sides each:\n", numDice, numSides);

    for (i = 0; i < numDice; i++) {
        printf("%d ", dice[i]);
    }

    printf("\nTotal: %d\n", total);

    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &playAgain);

    while (playAgain == 'y' || playAgain == 'Y') {
        main();
    }

    return 0;
}
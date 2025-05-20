//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, sides, i, j, total = 0;
    char playAgain = 'y';

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);
    printf("How many sides do the dice have? ");
    scanf("%d", &sides);

    printf("Rolling %d %d-sided dice...\n", numDice, sides);

    srand(time(NULL)); // Seed the random number generator with the current time

    for (i = 0; i < numDice; i++) {
        total += rand() % sides + 1; // Add the result of each roll to the total
        printf("Dice %d rolled a %d\n", i+1, rand() % sides + 1); // Display the result of each roll
    }

    printf("Total: %d\n", total);

    while (playAgain == 'y') {
        printf("Play again? (y/n) ");
        scanf(" %c", &playAgain);

        if (playAgain == 'y') {
            printf("How many dice do you want to roll? ");
            scanf("%d", &numDice);
            printf("How many sides do the dice have? ");
            scanf("%d", &sides);

            printf("Rolling %d %d-sided dice...\n", numDice, sides);

            srand(time(NULL)); // Seed the random number generator with the current time

            for (i = 0; i < numDice; i++) {
                total += rand() % sides + 1; // Add the result of each roll to the total
                printf("Dice %d rolled a %d\n", i+1, rand() % sides + 1); // Display the result of each roll
            }

            printf("Total: %d\n", total);
        }
    }

    return 0;
}
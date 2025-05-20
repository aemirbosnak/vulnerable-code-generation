//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, sides, maxRoll, totalRolls, i;
    int rollResult, total = 0;
    char playAgain = 'y';

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides do the dice have? ");
    scanf("%d", &sides);
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &totalRolls);

    srand(time(NULL));

    for (i = 1; i <= totalRolls; i++) {
        rollResult = rand() % sides + 1;
        printf("Roll %d: %d\n", i, rollResult);
        total += rollResult;
    }

    printf("\nTotal: %d\n", total);

    while (playAgain == 'y' || playAgain == 'Y') {
        printf("Play again? (y/n) ");
        scanf(" %c", &playAgain);

        if (playAgain == 'y' || playAgain == 'Y') {
            printf("How many dice would you like to roll? ");
            scanf("%d", &numDice);
            printf("How many sides do the dice have? ");
            scanf("%d", &sides);
            printf("How many times do you want to roll the dice? ");
            scanf("%d", &totalRolls);

            srand(time(NULL));

            for (i = 1; i <= totalRolls; i++) {
                rollResult = rand() % sides + 1;
                printf("Roll %d: %d\n", i, rollResult);
                total += rollResult;
            }

            printf("\nTotal: %d\n", total);
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_DICE 100

int main() {
    int numDice, rollCount, i, j, totalRolls = 0;
    int diceValues[MAX_DICE][SIDES] = {{0}};
    int maxValue = 0, minValue = 999;
    char playAgain = 'y';

    srand(time(NULL));

    while (playAgain == 'y') {
        printf("Enter the number of dice to roll (max %d): ", MAX_DICE);
        scanf("%d", &numDice);

        if (numDice > MAX_DICE) {
            printf("Error: too many dice!\n");
            numDice = MAX_DICE;
        }

        totalRolls = 0;
        for (i = 0; i < numDice; i++) {
            printf("Rolling dice %d...\n", i + 1);
            for (j = 0; j < SIDES; j++) {
                diceValues[i][j] = rand() % SIDES + 1;
                totalRolls += diceValues[i][j];
            }
        }

        printf("Total roll: %d\n", totalRolls);
        printf("Dice values:\n");
        for (i = 0; i < numDice; i++) {
            printf("Dice %d: ", i + 1);
            for (j = 0; j < SIDES; j++) {
                printf("%d ", diceValues[i][j]);
            }
            printf("\n");
        }

        maxValue = 0;
        minValue = 999;
        for (i = 0; i < numDice; i++) {
            for (j = 0; j < SIDES; j++) {
                if (diceValues[i][j] > maxValue) {
                    maxValue = diceValues[i][j];
                }
                if (diceValues[i][j] < minValue) {
                    minValue = diceValues[i][j];
                }
            }
        }

        printf("Max value: %d\n", maxValue);
        printf("Min value: %d\n", minValue);

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    return 0;
}
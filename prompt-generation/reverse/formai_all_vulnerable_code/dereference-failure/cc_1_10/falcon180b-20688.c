//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MIN_VALUE 1
#define MAX_VALUE 6

int main(void) {
    int numDice;
    int numRolls;
    int *dice;
    int i, j;
    int total;
    int maxValue;
    int minValue;
    int sum;

    printf("Enter the number of dice: ");
    scanf("%d", &numDice);

    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    dice = (int *)malloc(numDice * sizeof(int));

    for (i = 0; i < numDice; i++) {
        dice[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    printf("The dice values are:\n");
    for (i = 0; i < numDice; i++) {
        printf("%d ", dice[i]);
    }

    printf("\n");

    for (i = 0; i < numRolls; i++) {
        total = 0;
        maxValue = 0;
        minValue = MAX_VALUE;

        for (j = 0; j < numDice; j++) {
            sum = dice[j] + rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
            total += sum;

            if (sum > maxValue) {
                maxValue = sum;
            }

            if (sum < minValue) {
                minValue = sum;
            }
        }

        printf("Roll %d: Total = %d, Max = %d, Min = %d\n", i+1, total, maxValue, minValue);
    }

    free(dice);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

int main() {
    int numDice;
    int numSides;
    int *dice;
    int i, j;

    printf("Enter the number of dice: ");
    scanf("%d", &numDice);

    printf("Enter the number of sides on each dice: ");
    scanf("%d", &numSides);

    if (numDice <= 0 || numSides <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (numDice * numSides > MAX_DICE * MAX_SIDES) {
        printf("Too many sides or dice.\n");
        return 1;
    }

    dice = (int *) malloc(numDice * sizeof(int));

    for (i = 0; i < numDice; i++) {
        srand(time(NULL) + i);
        dice[i] = rand() % numSides + 1;
    }

    printf("Rolling %d dice with %d sides:\n", numDice, numSides);

    for (i = 0; i < numDice; i++) {
        printf("%d: ", i + 1);
        for (j = 0; j < numSides; j++) {
            if (j == dice[i]) {
                printf("%d ", j + 1);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    free(dice);

    return 0;
}
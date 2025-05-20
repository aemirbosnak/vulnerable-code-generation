//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACES 100000

int main() {
    int numDice, numFaces, numRolls;
    int *rolls;
    int i, j, k, faceValue;
    double mean, variance;
    char repeat;

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    printf("How many faces should each die have? ");
    scanf("%d", &numFaces);

    rolls = malloc(numDice * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < numDice; i++) {
        rolls[i] = rand() % numFaces + 1;
    }

    printf("You rolled:\n");
    for (i = 0; i < numDice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");

    printf("Would you like to repeat the roll? (y/n) ");
    scanf(" %c", &repeat);

    while (repeat == 'y' || repeat == 'Y') {
        for (i = 0; i < numDice; i++) {
            rolls[i] = rand() % numFaces + 1;
        }

        printf("You rolled:\n");
        for (i = 0; i < numDice; i++) {
            printf("%d ", rolls[i]);
        }
        printf("\n");

        printf("Would you like to repeat the roll? (y/n) ");
        scanf(" %c", &repeat);
    }

    free(rolls);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDices;
    int numSides;
    int **dice;
    int i, j, k;

    printf("Enter the number of dices: ");
    scanf("%d", &numDices);

    printf("Enter the number of sides for each dice: ");
    scanf("%d", &numSides);

    dice = (int **)malloc(numDices * sizeof(int *));
    for (i = 0; i < numDices; i++) {
        dice[i] = (int *)malloc(numSides * sizeof(int));
        for (j = 0; j < numSides; j++) {
            dice[i][j] = 1 + rand() % numSides; //initialize dice with random numbers between 1 and numSides
        }
    }

    printf("Dices:\n");
    for (i = 0; i < numDices; i++) {
        for (j = 0; j < numSides; j++) {
            printf("%d ", dice[i][j]);
        }
        printf("\n");
    }

    srand(time(NULL)); //seed the random number generator with the current time

    printf("\nRolling dices...\n");
    for (k = 0; k < 3; k++) {
        for (i = 0; i < numDices; i++) {
            for (j = 0; j < numSides; j++) {
                dice[i][j] = 1 + rand() % numSides; //roll the dice and update the values with new random numbers between 1 and numSides
            }
        }
        printf("\n");
        for (i = 0; i < numDices; i++) {
            for (j = 0; j < numSides; j++) {
                printf("%d ", dice[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (i = 0; i < numDices; i++) {
        free(dice[i]);
    }
    free(dice);

    return 0;
}
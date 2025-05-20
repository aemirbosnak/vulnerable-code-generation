//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_FACES 1000

int main() {
    int numDice, numFaces;
    int *dice;
    int total = 0;
    int maxRoll = 0;
    int minRoll = 999999;
    int maxRollIndex = 0;
    int minRollIndex = 0;
    int i, j;

    srand(time(NULL));

    // Ask user for number of dice and number of faces
    printf("Enter number of dice: ");
    scanf("%d", &numDice);
    printf("Enter number of faces: ");
    scanf("%d", &numFaces);

    // Allocate memory for dice array
    dice = (int*) malloc(numDice * sizeof(int));

    // Roll the dice
    for (i = 0; i < numDice; i++) {
        dice[i] = rand() % numFaces + 1;
        total += dice[i];

        // Update max and min rolls
        if (dice[i] > maxRoll) {
            maxRoll = dice[i];
            maxRollIndex = i;
        }
        if (dice[i] < minRoll) {
            minRoll = dice[i];
            minRollIndex = i;
        }
    }

    // Print results
    printf("Total: %d\n", total);
    printf("Max roll: %d on dice %d\n", maxRoll, maxRollIndex + 1);
    printf("Min roll: %d on dice %d\n", minRoll, minRollIndex + 1);

    // Free memory
    free(dice);

    return 0;
}
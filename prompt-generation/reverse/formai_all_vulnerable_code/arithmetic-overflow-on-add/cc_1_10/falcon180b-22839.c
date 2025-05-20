//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int numDice;
    int numSides;
    int *results;
} RollData;

int main() {
    int numRolls, i, j, k, numDice, numSides, totalSides;
    RollData rollData;
    srand(time(NULL));

    // Get number of rolls from user
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    // Get number of dice and sides for each roll
    for (i = 0; i < numRolls; i++) {
        printf("Enter the number of dice for roll %d: ", i+1);
        scanf("%d", &numDice);
        printf("Enter the number of sides for roll %d: ", i+1);
        scanf("%d", &numSides);
        totalSides += numDice * numSides;
    }

    // Allocate memory for results array
    rollData.numDice = numRolls;
    rollData.numSides = totalSides;
    rollData.results = (int*) malloc(totalSides * sizeof(int));

    // Perform rolls and store results
    for (i = 0; i < numRolls; i++) {
        for (j = 0; j < numDice; j++) {
            rollData.results[i*numDice+j] = rand() % numSides + 1;
        }
    }

    // Print results
    printf("\nResults:\n");
    for (i = 0; i < numRolls; i++) {
        printf("Roll %d: ", i+1);
        for (j = 0; j < numDice; j++) {
            printf("%d ", rollData.results[i*numDice+j]);
        }
        printf("\n");
    }

    // Free memory
    free(rollData.results);

    return 0;
}
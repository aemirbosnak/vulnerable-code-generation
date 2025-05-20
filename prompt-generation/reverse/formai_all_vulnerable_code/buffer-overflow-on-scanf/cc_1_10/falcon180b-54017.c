//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_DICE 100

int main() {
    int numDice, sides = SIDES;
    int *diceResults;
    int i, j, sum = 0;

    // Prompt user for number of dice to roll
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);

    // Check if numDice is within the allowed range
    if (numDice < 1 || numDice > MAX_DICE) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    // Allocate memory for diceResults
    diceResults = (int *) malloc(numDice * sizeof(int));

    // Check if memory allocation was successful
    if (diceResults == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    // Roll the dice and store the results in diceResults
    srand(time(NULL)); // Seed the random number generator with current time
    for (i = 0; i < numDice; i++) {
        diceResults[i] = rand() % sides + 1;
    }

    // Print the results of the dice rolls
    printf("You rolled %d dice:\n", numDice);
    for (i = 0; i < numDice; i++) {
        printf("%d ", diceResults[i]);
        sum += diceResults[i];
    }
    printf("\nTotal sum: %d\n", sum);

    // Free the memory allocated for diceResults
    free(diceResults);

    return 0;
}
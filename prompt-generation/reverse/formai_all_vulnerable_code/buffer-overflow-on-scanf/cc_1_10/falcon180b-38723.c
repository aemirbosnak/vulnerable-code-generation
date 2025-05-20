//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MIN_VALUE 1
#define MAX_VALUE 6

int main() {
    int numDice, i;
    int *diceValues = NULL;
    int totalValue = 0;

    srand(time(NULL));

    // Prompt the user for the number of dice to roll
    printf("Enter the number of dice to roll (1-100): ");
    scanf("%d", &numDice);

    // Check if the number of dice is within the valid range
    if (numDice < 1 || numDice > MAX_DICE) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    // Allocate memory for the dice values array
    diceValues = (int *) malloc(numDice * sizeof(int));

    // Check if the memory allocation was successful
    if (diceValues == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Roll the dice and store the values in the array
    for (i = 0; i < numDice; i++) {
        diceValues[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        totalValue += diceValues[i];
    }

    // Print the results
    printf("You rolled %d dice with a total value of %d.\n", numDice, totalValue);

    // Print the values of each dice
    printf("The values of the dice are:\n");
    for (i = 0; i < numDice; i++) {
        printf("%d\n", diceValues[i]);
    }

    // Free the memory allocated for the dice values array
    free(diceValues);

    return 0;
}
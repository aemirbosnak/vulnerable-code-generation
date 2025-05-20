//FormAI DATASET v1.0 Category: Dice Roller ; Style: statistical
/*
 * C Dice Roller
 *
 * This program simulates the roll of one or more dice, allowing the user
 * to specify the number of sides on each die, and the number of dice
 * to roll. The program then displays the results of the rolls and calculates
 * some basic statistics such as total roll value, average roll value and
 * frequency distribution of each possible roll.
 *
 * Author: John Doe
 * Date: December 1, 2021
 */

#include <stdio.h>      // for standard input/output
#include <stdlib.h>     // for random number generator

int main() {
    int numDice, numSides, rollCount;
    int *rolls;     // pointer to array of roll values
    int *freqDist;  // pointer to array of roll frequencies
    int totalValue = 0, maxValue, minValue;
    float averageValue;

    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &numSides);

    // Allocate memory for the arrays of roll values and frequencies
    rolls = (int*)malloc(numDice * sizeof(int));
    freqDist = (int*)calloc(numSides, sizeof(int));

    // Generate random rolls and update statistics
    for(rollCount = 0; rollCount < numDice; rollCount++) {
        rolls[rollCount] = rand() % numSides + 1;
        freqDist[rolls[rollCount] - 1]++;
        totalValue += rolls[rollCount];
    }

    // Calculate statistics
    maxValue = rolls[0];
    minValue = rolls[0];
    for(rollCount = 1; rollCount < numDice; rollCount++) {
        if(rolls[rollCount] > maxValue) { maxValue = rolls[rollCount]; }
        if(rolls[rollCount] < minValue) { minValue = rolls[rollCount]; }
    }
    averageValue = (float)totalValue / numDice;

    // Display results
    printf("\nRoll results:\n");
    for(rollCount = 0; rollCount < numDice; rollCount++) {
        printf("Die %d: %d\n", rollCount+1, rolls[rollCount]);
    }

    printf("\nTotal roll value: %d\n", totalValue);
    printf("Average roll value: %.2f\n", averageValue);
    printf("Maximum roll value: %d\n", maxValue);
    printf("Minimum roll value: %d\n", minValue);

    printf("\nFrequency distribution of rolls:\n");
    for(rollCount = 0; rollCount < numSides; rollCount++) {
        printf("%d: %d\n", rollCount+1, freqDist[rollCount]);
    }

    // Deallocate memory for the arrays
    free(rolls);
    free(freqDist);

    return 0;
}
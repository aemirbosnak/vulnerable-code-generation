//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_DICE 100
#define MAX_ROLLS 1000000

int main() {
    int numDice, numRolls, i, j, *dice, sides;
    double avg;
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? (1-%d): ", MAX_DICE);
    scanf("%d", &numDice);
    printf("How many times do you want to roll the dice? (1-%d): ", MAX_ROLLS);
    scanf("%d", &numRolls);

    dice = (int *)malloc(numDice * sizeof(int)); // Allocate memory for the dice array

    for (i = 0; i < numDice; i++) {
        printf("Enter the number of sides for dice %d: ", i+1);
        scanf("%d", &sides);
        if (sides < 2 || sides > SIDES) {
            printf("Invalid number of sides. Using default value of 6.\n");
            sides = SIDES;
        }
        dice[i] = sides;
    }

    for (i = 0; i < numRolls; i++) {
        for (j = 0; j < numDice; j++) {
            dice[j] = rand() % dice[j] + 1; // Roll the dice and store the result in the dice array
        }
        avg = 0;
        for (j = 0; j < numDice; j++) {
            avg += dice[j]; // Calculate the average of the dice rolls
        }
        avg /= numDice;
        printf("Roll %d: ", i+1);
        for (j = 0; j < numDice; j++) {
            printf("%d ", dice[j]);
        }
        printf("Average: %.2f\n", avg);
    }

    free(dice); // Free the memory allocated for the dice array

    return 0;
}
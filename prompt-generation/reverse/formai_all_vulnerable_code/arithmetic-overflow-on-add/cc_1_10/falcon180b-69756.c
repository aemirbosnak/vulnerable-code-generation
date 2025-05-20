//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MIN_DICE 1
#define SIDES 6

int main() {
    int numDice;
    int numRolls;
    int i;
    int j;
    int roll;
    int totalRolls = 0;
    int totalRollsSorted[MAX_DICE];
    int rollCount[SIDES] = {0};
    int maxRolls = 0;
    int minRolls = SIDES;

    // Seed the random number generator
    srand(time(NULL));

    // Get number of dice from user
    printf("Enter the number of dice to roll (between %d and %d): ", MIN_DICE, MAX_DICE);
    scanf("%d", &numDice);

    // Validate input
    if (numDice < MIN_DICE || numDice > MAX_DICE) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    // Get number of rolls from user
    printf("Enter the number of rolls to perform: ");
    scanf("%d", &numRolls);

    // Validate input
    if (numRolls < 1) {
        printf("Invalid number of rolls.\n");
        return 1;
    }

    // Perform the rolls
    for (i = 0; i < numRolls; i++) {
        for (j = 0; j < numDice; j++) {
            roll = rand() % SIDES + 1; // Roll a die
            rollCount[roll]++; // Increment the count for that roll
            totalRolls++; // Increment the total number of rolls
        }
    }

    // Sort the rolls in descending order
    for (i = 0; i < numDice; i++) {
        totalRollsSorted[i] = rollCount[SIDES - 1 - i];
        if (totalRollsSorted[i] > maxRolls) {
            maxRolls = totalRollsSorted[i];
        }
        if (totalRollsSorted[i] < minRolls) {
            minRolls = totalRollsSorted[i];
        }
    }

    // Display the results
    printf("Total number of rolls: %d\n", totalRolls);
    printf("Number of rolls per die:\n");
    for (i = 0; i < numDice; i++) {
        printf("%d: %d\n", i + 1, totalRollsSorted[i]);
    }
    printf("Minimum number of rolls: %d\n", minRolls);
    printf("Maximum number of rolls: %d\n", maxRolls);

    return 0;
}
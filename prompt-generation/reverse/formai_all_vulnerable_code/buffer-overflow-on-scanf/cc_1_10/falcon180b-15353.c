//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER_OF_DICE 10
#define MIN_NUMBER_OF_DICE 1

int main() {

    int numOfDice;
    int dice[MAX_NUMBER_OF_DICE];
    int rollCount;
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of dice from the user
    printf("How many dice do you want to roll? (1 to %d): ", MAX_NUMBER_OF_DICE);
    scanf("%d", &numOfDice);

    // Make sure the number of dice is within the valid range
    if (numOfDice < MIN_NUMBER_OF_DICE || numOfDice > MAX_NUMBER_OF_DICE) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    // Roll the dice and display the results
    printf("Rolling %d dice...\n", numOfDice);
    for (i = 0; i < numOfDice; i++) {
        dice[i] = rand() % 6 + 1;
        printf("%d ", dice[i]);
    }
    printf("\n");

    // Ask the user if they want to roll again
    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &rollCount);

    // Make sure the user entered a valid response
    if (rollCount!= 'y' && rollCount!= 'n') {
        printf("Invalid response.\n");
        return 1;
    }

    // If the user wants to roll again, repeat the process
    while (rollCount == 'y') {
        printf("Rolling %d dice...\n", numOfDice);
        for (i = 0; i < numOfDice; i++) {
            dice[i] = rand() % 6 + 1;
            printf("%d ", dice[i]);
        }
        printf("\n");

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &rollCount);

        // Make sure the user entered a valid response
        if (rollCount!= 'y' && rollCount!= 'n') {
            printf("Invalid response.\n");
            return 1;
        }
    }

    return 0;
}
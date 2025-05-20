//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MIN_DICE_VALUE 1
#define MAX_DICE_VALUE 6
#define DICE_VALUE_RANGE (MAX_DICE_VALUE - MIN_DICE_VALUE + 1)

int main() {
    int numDice, i, diceValue, total = 0;
    char rollAgain = 'y';

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of dice from the user
    printf("How many dice do you want to roll? (1-100): ");
    scanf("%d", &numDice);

    // Make sure the number of dice is within the allowed range
    if (numDice < 1 || numDice > MAX_DICE) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    // Roll the dice and calculate the total
    for (i = 0; i < numDice; i++) {
        diceValue = rand() % DICE_VALUE_RANGE + MIN_DICE_VALUE;
        printf("Dice %d rolled a %d.\n", i+1, diceValue);
        total += diceValue;
    }

    // Print the total
    printf("The total is: %d\n", total);

    // Ask the user if they want to roll again
    while (rollAgain == 'y' || rollAgain == 'Y') {
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &rollAgain);

        // Roll the dice again and calculate the total
        for (i = 0; i < numDice; i++) {
            diceValue = rand() % DICE_VALUE_RANGE + MIN_DICE_VALUE;
            printf("Dice %d rolled a %d.\n", i+1, diceValue);
            total += diceValue;
        }

        // Print the total
        printf("The total is: %d\n", total);
    }

    return 0;
}
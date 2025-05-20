//FormAI DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll dice
int rollDice(int numDice, int sides) {
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        total += (rand() % sides) + 1;
    }
    return total;
}

int main() {
    int numDice, sides, rollCount;
    char input;

    // Seed the random number generator
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Dice Roller!\n\n");

    do {
        // Prompt the user for input
        printf("How many dice would you like to roll? (1-10): ");
        scanf("%d", &numDice);

        // Validate input
        while (numDice < 1 || numDice > 10) {
            printf("Invalid input, please choose a value between 1 and 10: ");
            scanf("%d", &numDice);
        }

        printf("How many sides should the dice have? (2-100): ");
        scanf("%d", &sides);

        // Validate input
        while (sides < 2 || sides > 100) {
            printf("Invalid input, please choose a value between 2 and 100: ");
            scanf("%d", &sides);
        }

        printf("How many times do you want to roll the dice? (1-100): ");
        scanf("%d", &rollCount);

        // Validate input
        while (rollCount < 1 || rollCount > 100) {
            printf("Invalid input, please choose a value between 1 and 100: ");
            scanf("%d", &rollCount);
        }

        // Roll the dice and print the results
        printf("\nRolling %d %d-sided dice %d times...\n\n", numDice, sides, rollCount);

        for (int i = 0; i < rollCount; i++) {
            printf("Roll %d: %d\n", i+1, rollDice(numDice, sides));
        }

        // Prompt the user to play again
        printf("\nWould you like to roll again? (y/n): ");
        scanf(" %c", &input);

    } while (input == 'y' || input == 'Y');

    // Thank you message
    printf("\nThank you for using the Dice Roller! Have a great day!\n");

    return 0;
}
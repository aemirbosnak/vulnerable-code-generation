//FormAI DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice and display the result
void rollDice(int numSides) {
    int result = (rand() % numSides) + 1;
    printf("You rolled a %d.\n", result);
}

// Main function
int main() {
    int numSides, numRolls;
    char choice;

    // Seed the random number generator
    srand(time(NULL));

    // Ask user for input
    printf("Welcome to the C Dice Roller!\n");
    printf("How many sides does your dice have? ");
    scanf("%d", &numSides);
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);

    // Roll the dice
    for (int i = 1; i <= numRolls; i++) {
        rollDice(numSides);
    }

    // Ask user if they want to roll again
    printf("Would you like to roll again? (Y/N) ");
    scanf(" %c", &choice);

    // Keep rolling until the user says 'N'
    while (choice == 'Y' || choice == 'y') {
        // Ask user for input
        printf("How many sides does your dice have? ");
        scanf("%d", &numSides);
        printf("How many times would you like to roll the dice? ");
        scanf("%d", &numRolls);

        // Roll the dice
        for (int i = 1; i <= numRolls; i++) {
            rollDice(numSides);
        }

        // Ask user if they want to roll again
        printf("Would you like to roll again? (Y/N) ");
        scanf(" %c", &choice);
    }

    // Thank the user for playing
    printf("Thank you for playing the C Dice Roller!\n");

    return 0;
}
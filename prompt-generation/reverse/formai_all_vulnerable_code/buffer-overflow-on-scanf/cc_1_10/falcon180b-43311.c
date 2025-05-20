//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, roll, total = 0;
    char playAgain;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the number of dice and sides per die
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);
    printf("How many sides do each die have? ");
    scanf("%d", &numSides);

    // Roll the dice and display the results
    for (int i = 0; i < numDice; i++) {
        roll = rand() % numSides + 1;
        printf("Roll %d: %d\n", i + 1, roll);
        total += roll;
    }

    // Ask the user if they want to play again
    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &playAgain);

    // If the user wants to play again, start over
    while (playAgain == 'y' || playAgain == 'Y') {
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);
        printf("How many sides do each die have? ");
        scanf("%d", &numSides);

        // Roll the dice and display the results
        for (int i = 0; i < numDice; i++) {
            roll = rand() % numSides + 1;
            printf("Roll %d: %d\n", i + 1, roll);
            total += roll;
        }

        // Ask the user if they want to play again
        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &playAgain);
    }

    printf("Total: %d\n", total);

    return 0;
}
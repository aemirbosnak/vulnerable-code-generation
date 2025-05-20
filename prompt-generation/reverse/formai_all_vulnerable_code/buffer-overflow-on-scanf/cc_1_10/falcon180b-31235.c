//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, sum = 0;
    char playAgain = 'y';

    srand(time(NULL));

    // Prompt user for number of dice and sides
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    printf("How many sides should each die have? ");
    scanf("%d", &numSides);

    // Roll the dice
    for (i = 0; i < numDice; i++) {
        int die = rand() % numSides + 1;
        printf("Die %d rolled a %d\n", i + 1, die);
        sum += die;
    }

    // Display the total sum of all dice rolls
    printf("The total sum of all dice rolls is %d\n", sum);

    // Ask the user if they want to play again
    while (playAgain == 'y') {
        printf("Do you want to roll the dice again? (y/n) ");
        scanf(" %c", &playAgain);

        if (playAgain == 'y') {
            numDice = rand() % 10 + 1;
            numSides = rand() % 20 + 1;

            printf("You will now roll %d dice with %d sides.\n", numDice, numSides);

            for (i = 0; i < numDice; i++) {
                int die = rand() % numSides + 1;
                printf("Die %d rolled a %d\n", i + 1, die);
                sum += die;
            }

            printf("The total sum of all dice rolls is %d\n", sum);
        }
    }

    return 0;
}
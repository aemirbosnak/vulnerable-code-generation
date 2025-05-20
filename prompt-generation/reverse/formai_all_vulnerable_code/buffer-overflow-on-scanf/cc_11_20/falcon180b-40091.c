//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, sides, i, j, total;
    char playAgain;

    do {
        printf("Enter the number of dice to roll (1-100): ");
        scanf("%d", &numDice);
        if (numDice < 1 || numDice > 100) {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
        }
    } while (numDice < 1 || numDice > 100);

    do {
        printf("Enter the number of sides on each die (1-100): ");
        scanf("%d", &sides);
        if (sides < 1 || sides > 100) {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
        }
    } while (sides < 1 || sides > 100);

    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Rolling %d %d-sided dice...\n", numDice, sides);

    for (i = 0; i < numDice; i++) {
        total = 0;
        for (j = 0; j < sides; j++) {
            total += rand() % sides + 1; // Roll a random number between 1 and sides, inclusive
        }
        printf("Dice %d rolled a total of %d.\n", i+1, total);
    }

    printf("Would you like to roll the dice again? (y/n): ");
    scanf(" %c", &playAgain);

    while (playAgain!= 'y' && playAgain!= 'n') {
        printf("Invalid input. Please enter 'y' or 'n': ");
        scanf(" %c", &playAgain);
    }

    if (playAgain == 'y') {
        main(); // Recursive call to restart the program
    } else {
        printf("Exiting program.\n");
    }

    return 0;
}
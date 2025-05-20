//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, roll;
    char playAgain;

    srand(time(NULL)); // Initialize random number generator

    // Prompt user for number of dice and sides
    printf("Welcome to the Shocking Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides should each die have? ");
    scanf("%d", &numSides);

    // Roll the dice
    for (i = 1; i <= numDice; i++) {
        roll = rand() % numSides + 1;
        printf("You rolled a %d on dice %d.\n", roll, i);
    }

    // Ask user if they want to play again
    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &playAgain);

    while (playAgain == 'y' || playAgain == 'Y') {
        // Clear screen
        system("clear");

        // Prompt user for number of dice and sides
        printf("Welcome to the Shocking Dice Roller!\n");
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);
        printf("How many sides should each die have? ");
        scanf("%d", &numSides);

        // Roll the dice
        for (i = 1; i <= numDice; i++) {
            roll = rand() % numSides + 1;
            printf("You rolled a %d on dice %d.\n", roll, i);
        }

        // Ask user if they want to play again
        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &playAgain);
    }

    return 0;
}
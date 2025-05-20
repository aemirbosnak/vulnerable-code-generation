//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, maxRolls = 100, totalRolls = 0, roll, sum = 0;
    float average;
    char playAgain;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the number of dice and sides per die
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides per die: ");
    scanf("%d", &numSides);

    // Roll the dice and display the results
    printf("Rolling %d %d-sided dice...\n", numDice, numSides);
    for (int i = 0; i < numDice; i++) {
        roll = rand() % numSides + 1;
        printf("Dice %d rolled a %d\n", i+1, roll);
        sum += roll;
        totalRolls++;
    }

    // Calculate the average roll
    average = (float) sum / numDice;
    printf("The average roll was %.2f\n", average);

    // Ask the user if they want to play again
    printf("Do you want to roll the dice again? (y/n): ");
    scanf(" %c", &playAgain);

    // Repeat the program if the user wants to play again
    while (playAgain == 'y' || playAgain == 'Y') {
        totalRolls = 0;
        sum = 0;

        // Roll the dice and display the results
        printf("Rolling %d %d-sided dice...\n", numDice, numSides);
        for (int i = 0; i < numDice; i++) {
            roll = rand() % numSides + 1;
            printf("Dice %d rolled a %d\n", i+1, roll);
            sum += roll;
            totalRolls++;
        }

        // Calculate the average roll
        average = (float) sum / numDice;
        printf("The average roll was %.2f\n", average);

        // Ask the user if they want to play again
        printf("Do you want to roll the dice again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    return 0;
}
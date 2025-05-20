//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, roll;
    char choice;
    double average;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Ask user for number of dice and sides
    printf("Enter number of dice: ");
    scanf("%d", &numDice);
    printf("Enter number of sides: ");
    scanf("%d", &numSides);

    // Roll the dice
    int dice[numDice];
    for (i = 0; i < numDice; i++) {
        dice[i] = rand() % numSides + 1;
    }

    // Ask user if they want to roll again
    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &choice);

    // Loop until user decides to quit
    while (choice == 'y' || choice == 'Y') {
        // Roll the dice
        for (i = 0; i < numDice; i++) {
            dice[i] = rand() % numSides + 1;
        }

        // Calculate average roll
        average = 0;
        for (i = 0; i < numDice; i++) {
            average += dice[i];
        }
        average /= numDice;

        // Print results
        printf("Rolls: ");
        for (i = 0; i < numDice; i++) {
            printf("%d ", dice[i]);
        }
        printf("\nAverage: %.2f\n", average);

        // Ask user if they want to roll again
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}
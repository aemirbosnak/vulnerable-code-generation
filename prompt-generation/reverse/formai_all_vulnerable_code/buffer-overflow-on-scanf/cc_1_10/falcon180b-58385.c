//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main() {
    int numDice, numSides, numRolls, i, j, temp;
    int diceArray[100];
    char choice;
    srand(time(NULL));

    // Get user input
    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &numSides);

    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    // Roll the dice
    for (i = 0; i < numRolls; i++) {
        for (j = 0; j < numDice; j++) {
            diceArray[j] = rand() % numSides + 1;
        }

        // Sort the dice in ascending order
        for (j = 0; j < numDice - 1; j++) {
            for (int k = 0; k < numDice - j - 1; k++) {
                if (diceArray[k] > diceArray[k+1]) {
                    temp = diceArray[k];
                    diceArray[k] = diceArray[k+1];
                    diceArray[k+1] = temp;
                }
            }
        }

        // Print the results
        printf("Roll #%d:\n", i+1);
        for (j = 0; j < numDice; j++) {
            printf("%d ", diceArray[j]);
        }
        printf("\n");
    }

    // Ask user if they want to roll again
    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Exiting program...\n");
    }

    return 0;
}
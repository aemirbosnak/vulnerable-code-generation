//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, k, sum;
    int *diceArray;
    float mean, variance;
    char choice;

    srand(time(0));

    do {
        printf("Enter the number of dice: ");
        scanf("%d", &numDice);
        if (numDice <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numDice <= 0);

    do {
        printf("Enter the number of sides on each dice: ");
        scanf("%d", &numSides);
        if (numSides <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numSides <= 0);

    diceArray = (int*) malloc(numDice * sizeof(int));

    for (i = 0; i < numDice; i++) {
        diceArray[i] = rand() % numSides + 1;
        printf("Dice %d rolled: %d\n", i+1, diceArray[i]);
    }

    printf("Would you like to calculate the mean and variance? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        sum = 0;
        for (i = 0; i < numDice; i++) {
            sum += diceArray[i];
        }
        mean = (float) sum / numDice;
        variance = 0;
        for (i = 0; i < numDice; i++) {
            variance += (diceArray[i] - mean) * (diceArray[i] - mean);
        }
        variance = variance / numDice;
        printf("Mean: %.2f\n", mean);
        printf("Variance: %.2f\n", variance);
    }

    free(diceArray);

    return 0;
}
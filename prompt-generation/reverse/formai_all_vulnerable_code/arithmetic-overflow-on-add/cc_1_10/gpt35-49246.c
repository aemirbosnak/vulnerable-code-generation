//FormAI DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numDice, numSides;
    int i, j;
    int rolls[10][10];

    srand(time(0)); // Initialize random number generator

    printf("Welcome to the Dice Roller program.\n");
    printf("Enter number of dice to roll: ");
    scanf("%d", &numDice);
    printf("Enter number of sides on the dice: ");
    scanf("%d", &numSides);

    // Roll the dice and store the results in the rolls array
    for (i = 0; i < numDice; i++)
    {
        for (j = 0; j < numDice; j++)
        {
            int roll = rand() % numSides + 1;
            rolls[i][j] = roll;
        }
    }

    // Print out the results of the rolls
    printf("Results:\n");
    for (i = 0; i < numDice; i++)
    {
        for (j = 0; j < numDice; j++)
        {
            printf("%d ", rolls[i][j]);
        }
        printf("\n");
    }

    // Calculate the sum of each row and column
    int rowSums[10] = {0};
    int colSums[10] = {0};
    for (i = 0; i < numDice; i++)
    {
        for (j = 0; j < numDice; j++)
        {
            rowSums[i] += rolls[i][j];
            colSums[j] += rolls[i][j];
        }
    }

    // Print out the row and column sums
    printf("\nRow Sums:\n");
    for (i = 0; i < numDice; i++)
    {
        printf("%d ", rowSums[i]);
    }
    printf("\n\nColumn Sums:\n");
    for (i = 0; i < numDice; i++)
    {
        printf("%d ", colSums[i]);
    }

    return 0;
}
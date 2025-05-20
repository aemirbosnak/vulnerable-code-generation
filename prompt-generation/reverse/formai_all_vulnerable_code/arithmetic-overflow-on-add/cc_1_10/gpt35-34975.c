//FormAI DATASET v1.0 Category: Dice Roller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numRolls;
    int numSides;
    int i, j;
    int rollSum = 0;
    int rolling = 1;
    char choice;

    printf("Welcome to the Ultra Precise C Dice Roller!\n");

    while (rolling)
    {
        printf("How many rolls? ");
        scanf("%d", &numRolls);

        printf("How many sides? ");
        scanf("%d", &numSides);

        srand(time(0)); // seed the random number generator using the current time

        printf("\nRolling...\n");

        for (i = 1; i <= numRolls; i++)
        {
            int roll = rand() % numSides + 1;
            printf("Roll %d: %d\n", i, roll);
            rollSum += roll;
        }

        printf("\nRoll sum: %d\n", rollSum);

        printf("Do you want to roll again? (y or n) ");
        scanf(" %c", &choice);

        if (choice == 'n')
        {
            rolling = 0;
        }

        rollSum = 0;
    }

    printf("Thanks for using the Ultra Precise C Dice Roller!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, n, roll;
    char choice = 'y';

    // Seed random number generator
    srand(time(NULL));

    // While loop to continue rolling dice until user chooses to stop
    while (choice == 'y')
    {
        printf("\nHow many dice would you like to roll? ");
        scanf("%d", &n);

        // Validate user input
        if (n < 1)
        {
            printf("Invalid input. You must roll at least one die.\n");
            continue;
        }

        printf("How many sides should each die have? ");
        int sides;
        scanf("%d", &sides);

        if (sides < 2)
        {
            printf("Invalid input. Dice must have at least two sides.\n");
            continue;
        }

        printf("Rolling %d %d-sided dice:\n", n, sides);

        // Loop to roll dice and display results
        for (i = 1; i <= n; i++)
        {
            roll = rand() % sides + 1;
            printf("Die %d: %d\n", i, roll);
        }

        // Ask user if they want to roll again
        printf("Roll again? (y/n) ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the dice roller!\n");

    return 0;
}
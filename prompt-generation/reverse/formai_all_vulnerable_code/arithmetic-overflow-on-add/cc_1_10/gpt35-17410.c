//FormAI DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice, sides, total = 0;
    char response;

    srand(time(NULL)); // seeds the random number generator with the current time

    printf("Welcome to the Dice Roller! How many sides does the dice have?: ");
    scanf("%d", &sides);

    printf("\nHow many dice do you want to roll?: ");
    scanf("%d", &dice);

    for (int i = 1; i <= dice; i++)
    {
        int result = rand() % sides + 1;
        printf("\nDice #%d: %d", i, result);
        total += result;
    }

    printf("\n\nTotal: %d\n", total);

    while (1) // loop to handle invalid user responses
    {
        printf("\nWould you like to roll again? (y/n): ");
        scanf(" %c", &response);

        if (response == 'y' || response == 'Y')
        {
            printf("\nRolling again...\n");
            total = 0; // reset the total before rolling again

            for (int i = 1; i <= dice; i++)
            {
                int result = rand() % sides + 1;
                printf("\nDice #%d: %d", i, result);
                total += result;
            }

            printf("\n\nTotal: %d\n", total);
        }
        else if (response == 'n' || response == 'N')
        {
            printf("\nThanks for playing!\n");
            break;
        }
        else
        {
            printf("\nInvalid response. Please enter 'y' or 'n'.\n");
        }
    }

    return 0;
}
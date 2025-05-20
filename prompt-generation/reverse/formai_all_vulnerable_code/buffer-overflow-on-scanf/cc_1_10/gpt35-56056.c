//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rollover, dice;
    char choice;

    srand(time(NULL));
    printf("Welcome to the Dice Roller! Press 'r' to roll the dice, or 'q' to quit.\n");

    while (choice != 'q')
    {
        printf("Choose your dice: \n 1) 4-sided \n 2) 6-sided \n 3) 8-sided \n 4) 10-sided \n 5) 12-sided \n 6) 20-sided\n");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1':
                dice = 4;
                break;
            case '2':
                dice = 6;
                break;
            case '3':
                dice = 8;
                break;
            case '4':
                dice = 10;
                break;
            case '5':
                dice = 12;
                break;
            case '6':
                dice = 20;
                break;
            default:
                printf("That's not a valid choice, try again!\n");
                continue;
        }

        printf("How many times do you want to roll the dice? ");
        scanf("%d", &rollover);

        for (int i = 0; i < rollover; i++)
        {
            printf("Rolling the %d-sided dice... Your result is: %d\n", dice, (rand() % dice) + 1);
        }

        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &choice);

        if (choice != 'y')
        {
            break;
        }
    }

    printf("Goodbye and happy rolling!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, n, dice_roll;

    // seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &n);

    // check for valid input
    while(n <= 0)
    {
        printf("Invalid input, please try again: ");
        scanf("%d", &n);
    }

    printf("\n");

    // roll the dice
    for(i = 1; i <= n; i++)
    {
        dice_roll = rand() % 6 + 1;
        printf("Dice %d: %d\n", i, dice_roll);
    }

    printf("\n");

    // ask the user if they want to roll again
    char choice;
    printf("Would you like to roll again? (Y/N) ");
    scanf(" %c", &choice);

    // roll again if user answers yes
    while(choice == 'Y' || choice == 'y')
    {
        printf("\n");

        printf("How many dice would you like to roll? ");
        scanf("%d", &n);

        while(n <= 0)
        {
            printf("Invalid input, please try again: ");
            scanf("%d", &n);
        }

        printf("\n");

        for(i = 1; i <= n; i++)
        {
            dice_roll = rand() % 6 + 1;
            printf("Dice %d: %d\n", i, dice_roll);
        }

        printf("\n");

        printf("Would you like to roll again? (Y/N) ");
        scanf(" %c", &choice);
    }

    printf("Thanks for using the Dice Roller! Goodbye!\n");

    return 0;
}
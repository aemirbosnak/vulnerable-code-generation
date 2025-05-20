//FormAI DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_dice(int rolls);

int main()
{
    int num_rolls;
    char play_again = 'y';

    printf("Welcome to the dice roller!\n");

    while(play_again == 'y')
    {
        printf("How many times would you like to roll the dice? (1-10) ");
        scanf("%d", &num_rolls);

        if(num_rolls < 1 || num_rolls > 10)
        {
            printf("Invalid input. Please enter a number between 1 and 10.\n");
            continue;
        }

        roll_dice(num_rolls);

        printf("Would you like to play again? (y/n) ");
        scanf("\n%c", &play_again);
    }

    printf("Thanks for playing. Goodbye!\n");

    return 0;
}

void roll_dice(int rolls)
{
    int dice1, dice2;
    int total = 0;
    srand(time(NULL));

    printf("Rolling %d times...\n", rolls);

    for(int i = 1; i <= rolls; i++)
    {
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        total += dice1 + dice2;
        printf("Roll %d: %d + %d = %d\n", i, dice1, dice2, dice1+dice2);
    }

    printf("Total points for %d rolls: %d\n", rolls, total);
}
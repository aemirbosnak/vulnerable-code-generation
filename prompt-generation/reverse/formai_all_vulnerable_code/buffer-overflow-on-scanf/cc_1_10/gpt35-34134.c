//FormAI DATASET v1.0 Category: Table Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
int play_game(void);

int main(void)
{
    char play_again = 'y';
    int wins = 0, losses = 0;

    srand((unsigned) time(NULL));

    printf("\nWelcome to the Roll Dice Table Game!\n");

    do
    {
        if(play_game() == 1)
        {
            wins++;
        }
        else
        {
            losses++;
        }

        printf("\nWins: %d   Losses: %d\n", wins, losses);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        
    }while(play_again == 'y');

    printf("\nThanks for playing! Goodbye!\n");

    return 0;
}

int roll_dice(void)
{
    int dice_1 = rand() % 6 + 1;
    int dice_2 = rand() % 6 + 1;

    printf("\nYou rolled %d + %d = %d\n", dice_1, dice_2, dice_1 + dice_2);

    return dice_1 + dice_2; 
}

int play_game(void)
{
    int roll, point;
    printf("\nPress Enter to roll the dice...\n");
    getchar();

    roll = roll_dice();

    switch(roll)
    {
        case 7:
        case 11:
            printf("\nYou win!\n");
            return 1;
        case 2:
        case 3:
        case 12:
            printf("\nYou lose!\n");
            return 0;
        default:
            point = roll;
            printf("\nPoint is %d\n", point);
            break;
    }

    while(1)
    {
        printf("\nPress Enter to roll the dice...\n");
        getchar();

        roll = roll_dice();

        if(roll == point)
        {
            printf("\nYou win!\n");
            return 1;
        }
        else if(roll == 7)
        {
            printf("\nYou lose!\n");
            return 0;
        }
    }
}
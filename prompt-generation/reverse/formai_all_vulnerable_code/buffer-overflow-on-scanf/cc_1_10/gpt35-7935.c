//FormAI DATASET v1.0 Category: Table Game ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll_dice();
int play_game();
int get_point();
int roll_again(int);

int main()
{
    int win_count = 0, lose_count = 0, play_again = 1;

    system("clear"); // clear the console

    do
    {
        printf("Welcome to the C Table Game!\n\n");

        int result = play_game();

        if(result == 1)
        {
            printf("\nYou win!\n");
            win_count++;
        }
        else
        {
            printf("\nYou lose!\n");
            lose_count++;
        }

        printf("\nGames played: %d\nWins: %d\nLosses: %d\n", win_count + lose_count, win_count, lose_count);

        printf("\nDo you want to play again? (1 for Yes / 0 for No): ");
        scanf("%d", &play_again);

        system("clear"); // clear the console for next game

    }while(play_again != 0);

    printf("\nThank you for playing the C Table Game!\n");

    return 0;
}

// function to roll a dice
int roll_dice()
{
    return rand() % 6 + 1; // return a random number between 1 to 6
}

// function to play a game
int play_game()
{
    int point = 0, roll = 0;

    // roll the dice for the first time
    roll = roll_dice() + roll_dice();

    printf("\nYou rolled: %d\n", roll);

    switch(roll)
    {
        case 7:
        case 11:
            return 1; // win the game
            break;

        case 2:
        case 3:
        case 12:
            return 0; // lose the game
            break;

        default:
            point = roll;
            printf("Point is: %d\n", point);
            break;
    }

    // roll the dice again until win or lose
    while(1)
    {
        roll = roll_dice() + roll_dice();

        printf("\nYou rolled: %d\n", roll);

        if(roll == point)
            return 1; // win the game
        else if(roll == 7)
            return 0; // lose the game
    }
}

// function to get a point
int get_point()
{
    return roll_dice() + roll_dice();
}

// function to roll again
int roll_again(int point)
{
    printf("\nPoint is: %d\n", point);

    while(1)
    {
        int roll = roll_dice() + roll_dice();

        printf("\nYou rolled: %d\n", roll);

        if(roll == point)
            return 1; // win the game
        else if(roll == 7)
            return 0; // lose the game
    }
}
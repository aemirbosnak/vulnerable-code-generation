//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player_score = 0;
    int computer_score = 0;
    int rounds = 1;

    srand(time(NULL));

    printf("\nWelcome to the C Table Game!\n");

    while(rounds <= 5)
    {
        printf("\n--------------ROUND %d--------------\n", rounds);

        int player_choice = 0;

        printf("\nPlayer, it's your turn! Choose your number between 1 to 6: ");
        scanf("%d", &player_choice);

        if(player_choice < 1 || player_choice > 6)
        {
            printf("\nInvalid choice! Please enter a number between 1 to 6.\n");
            continue;
        }

        int computer_choice = rand() % 6 + 1;

        printf("\nThe computer chose: %d\n", computer_choice);

        if(player_choice > computer_choice)
        {
            printf("\nCongratulations, you won this round!\n");
            player_score++;
        }
        else if(player_choice < computer_choice)
        {
            printf("\nSorry, the computer won this round.\n");
            computer_score++;
        }
        else
        {
            printf("\nIt's a tie, no one gets a point.\n");
        }

        rounds++;

        printf("\nCurrent score: Player %d - Computer %d\n", player_score, computer_score);
    }

    if(player_score > computer_score)
    {
        printf("\nYou won the game, congratulations!\n");
    }
    else if(player_score < computer_score)
    {
        printf("\nSorry, the computer won the game.\n");
    }
    else
    {
        printf("\nIt's a tie, no one wins the game.\n");
    }

    printf("\nThanks for playing C Table Game!\n");

    return 0;
}
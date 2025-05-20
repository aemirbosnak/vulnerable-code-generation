//FormAI DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //initialize variables
    int player1Sum = 0, player2Sum = 0, dice1, dice2, turn = 1, totalScore = 0;
    char decision;

    //display game rules to user
    printf("Welcome to the C Table Game!\n");
    printf("Each player rolls two dice per turn and adds them up.\n");
    printf("The sum is added to the current player's score.\n");
    printf("The game ends when a player reaches 100 points.\n\n");

    //game loop
    while(player1Sum <= 100 && player2Sum <= 100)
    {
        printf("Player %d's turn\n", turn);
        printf("Rolling dice...\n");

        //roll dice randomly
        srand(time(0));
        dice1 = (rand() % 6) + 1;
        dice2 = (rand() % 6) + 1;
        printf("Player %d rolled a %d and a %d\n", turn, dice1, dice2);
        totalScore = dice1 + dice2;

        //update player's score
        if(turn == 1)
        {
            player1Sum += totalScore;
            printf("Player 1's total score is now %d\n", player1Sum);
        }
        else
        {
            player2Sum += totalScore;
            printf("Player 2's total score is now %d\n", player2Sum);
        }

        //check if player has won
        if(player1Sum >= 100)
        {
            printf("Player 1 wins!\n");
            break;
        }
        else if(player2Sum >= 100)
        {
            printf("Player 2 wins!\n");
            break;
        }

        //ask player if they want to roll again
        printf("Do you want to roll again? (Y/N)\n");
        scanf(" %c", &decision);
        if(decision == 'n' || decision == 'N')
        {
            //switch to other player's turn
            if(turn == 1)
            {
                turn = 2;
            }
            else
            {
                turn = 1;
            }
        }
    }

    return 0;
}
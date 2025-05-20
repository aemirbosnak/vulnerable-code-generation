//FormAI DATASET v1.0 Category: Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char board[3][3];
    int i, j, count = 0, winner = 0, player = 1, choice;

    srand(time(0));

    printf("\n");
    printf("Welcome to my artistic Tic Tac Toe Game!\n");
    printf("\n");

    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            board[i][j] = ' ';
        }
    }

    while (count < 9 && winner == 0) 
    {
        printf("Player %d, please enter your move (1-9): ", player);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) 
        {
            printf("Invalid move, please try again.\n");
            continue;
        }

        i = (choice-1) / 3;
        j = (choice-1) % 3;

        if (board[i][j] != ' ') 
        {
            printf("That space is already taken, please try again.\n");
            continue;
        }

        if (player == 1) 
        {
            board[i][j] = 'X';
            player = 2;
        } 
        else 
        {
            board[i][j] = 'O';
            player = 1;
        }

        count++;

        for (i = 0; i < 3; i++) 
        {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
            {
                winner = 1;
                break;
            }

            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
            {
                winner = 1;
                break;
            }
        }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
        {
            winner = 1;
        }

        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
        {
            winner = 1;
        }

        if (winner == 1) 
        {
            printf("\n");
            printf("Player %d wins!\n", player);
            printf("\n");
            break;
        }
        
        if (count == 9 && winner == 0) 
        {
            printf("\n");
            printf("It's a tie!\n");
            printf("\n");
            break;
        }
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char board[6][6] = {{'a', 'b', 'c', 'd', 'e', 'f'},
                              {'g', 'h', 'i', 'j', 'k', 'l'},
                              {'m', 'n', 'o', 'p', 'q', 'r'},
                              {'s', 't', 'u', 'v', 'w', 'x'},
                              {'y', 'z', 'A', 'B', 'C', 'D'},
                              {'E', 'F', 'G', 'H', 'I', 'J'}};

    int player_1_wins = 0;
    int player_2_wins = 0;
    int turn = 0;

    while (player_1_wins == 0 && player_2_wins == 0)
    {
        // Get the player's move
        int move = 0;
        printf("Enter your move (1-6): ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > 6)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece on the board
        board[move-1][move-1] = 'X';

        // Check if the player has won
        if (check_win(board, move, player_1_wins, player_2_wins))
        {
            // The player has won
            printf("Congratulations! You have won!\n");
            player_1_wins++;
        }
        else
        {
            // The player has not won, so it is the next turn
            turn++;
        }
    }

    // The game is over
    printf("Thank you for playing! The game is over.\n");

    return 0;
}

int check_win(char board[][6], int move, int *player_1_wins, int *player_2_wins)
{
    // Check if the player has won horizontally
    for (int i = 0; i < 6; i++)
    {
        if (board[move-1][i] == 'X' && board[move-1][i] == board[move-1][i+1] && board[move-1][i] == board[move-1][i+2] && board[move-1][i] == board[move-1][i+3] && board[move-1][i] == board[move-1][i+4] && board[move-1][i] == board[move-1][i+5])
        {
            *player_1_wins++;
            return 1;
        }
    }

    // Check if the player has won vertically
    for (int i = 0; i < 6; i++)
    {
        if (board[i][move-1] == 'X' && board[i][move-1] == board[i+1][move-1] && board[i][move-1] == board[i+2][move-1] && board[i][move-1] == board[i+3][move-1] && board[i][move-1] == board[i+4][move-1] && board[i][move-1] == board[i+5][move-1])
        {
            *player_1_wins++;
            return 1;
        }
    }

    // Check if the player has won diagonally
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == 'X' && board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3] && board[i][j] == board[i+4][j+4] && board[i][j] == board[i+5][j+5])
            {
                *player_1_wins++;
                return 1;
            }
        }
    }

    // The player has not won
    return 0;
}
//Gemma-7B DATASET v1.0 Category: Table Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    // Initialize the board
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place the pieces
    board[2][3] = 1;
    board[4][2] = 2;

    // Check if the player won
    int winner = check_winner(board);

    // Print the board
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Print the winner
    if (winner == 1)
    {
        printf("Player 1 won!");
    }
    else if (winner == 2)
    {
        printf("Player 2 won!");
    }
    else
    {
        printf("It's a draw!");
    }

    return 0;
}

int check_winner(int **board)
{
    // Check rows
    for (int r = 0; r < 6; r++)
    {
        if (board[r][0] == board[r][1] && board[r][1] == board[r][2] && board[r][2] == board[r][3] && board[r][3] == board[r][4] && board[r][4] == board[r][5] && board[r][5] == board[r][6])
        {
            return board[r][0];
        }
    }

    // Check columns
    for (int c = 0; c < 6; c++)
    {
        if (board[0][c] == board[1][c] && board[1][c] == board[2][c] && board[2][c] == board[3][c] && board[3][c] == board[4][c] && board[4][c] == board[5][c] && board[5][c] == board[6][c])
        {
            return board[0][c];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[4][4] == board[5][5] && board[5][5] == board[6][6])
    {
        return board[0][0];
    }

    // If no winner, return 0
    return 0;
}
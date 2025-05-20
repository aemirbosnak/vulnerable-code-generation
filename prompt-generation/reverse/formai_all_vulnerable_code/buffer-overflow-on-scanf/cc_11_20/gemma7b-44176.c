//Gemma-7B DATASET v1.0 Category: Table Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Game Board Setup
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    // Player's Turn
    int playerTurn = 1;

    // Game Loop
    while (!board[5][5])
    {
        // Get Player's Move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Validate Move
        if (board[row][col] != 0 || row < 0 || row > 5 || col < 0 || col > 5)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place Piece
        board[row][col] = playerTurn;

        // Check if Player Won
        if (checkWin(board, playerTurn))
        {
            printf("Congratulations! You won!\n");
            break;
        }

        // Next Turn
        playerTurn *= -1;
    }

    // Game Over
    if (board[5][5] == 0)
    {
        printf("It's a draw!\n");
    }

    return 0;
}

int checkWin(int **board, int playerTurn)
{
    // Check rows
    for (int i = 0; i < 6; i++)
    {
        if (board[i][0] == playerTurn && board[i][1] == playerTurn && board[i][2] == playerTurn && board[i][3] == playerTurn && board[i][4] == playerTurn && board[i][5] == playerTurn)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 6; j++)
    {
        if (board[0][j] == playerTurn && board[1][j] == playerTurn && board[2][j] == playerTurn && board[3][j] == playerTurn && board[4][j] == playerTurn && board[5][j] == playerTurn)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == playerTurn && board[1][1] == playerTurn && board[2][2] == playerTurn && board[3][3] == playerTurn && board[4][4] == playerTurn && board[5][5] == playerTurn)
    {
        return 1;
    }

    // No win
    return 0;
}
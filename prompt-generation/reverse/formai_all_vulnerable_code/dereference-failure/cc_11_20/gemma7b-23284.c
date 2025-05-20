//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int currentPlayer = PLAYER_X;
    int gameWon = 0;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    while (!gameWon && board[BOARD_SIZE - 1][BOARD_SIZE - 1] == 0)
    {
        // Get the move
        int moveX = rand() % BOARD_SIZE;
        int moveY = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (board[moveX][moveY] != 0)
        {
            continue;
        }

        // Make the move
        board[moveX][moveY] = currentPlayer;

        // Check if the player has won
        gameWon = checkWin(currentPlayer, board);

        // Switch the player
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Game over
    if (gameWon)
    {
        printf("Player %d won!\n", currentPlayer);
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}

int checkWin(int player, int **board)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }
    else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    // No win
    return 0;
}
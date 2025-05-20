//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell
{
    char value;
    int row;
    int col;
} Cell;

Cell board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard()
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            board[r][c].value = ' ';
            board[r][c].row = r;
            board[r][c].col = c;
        }
    }
}

void printBoard()
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            printf("%c ", board[r][c].value);
        }
        printf("\n");
    }
}

void placePiece(char piece, int row, int col)
{
    if (board[row][col].value != ' ')
    {
        return;
    }

    board[row][col].value = piece;
}

int checkWin(char piece)
{
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0].value == piece && board[r][1].value == piece && board[r][2].value == piece)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c].value == piece && board[1][c].value == piece && board[2][c].value == piece)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0].value == piece && board[1][1].value == piece && board[2][2].value == piece)
    {
        return 1;
    }

    if (board[0][2].value == piece && board[1][1].value == piece && board[2][0].value == piece)
    {
        return 1;
    }

    return 0;
}

int main()
{
    initializeBoard();

    char currentPlayer = 'X';
    char winner = ' ';

    // Game loop
    while (winner == ' ' && !checkWin(currentPlayer))
    {
        int row, col;

        // Get move from the player
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);

        // Place the piece
        placePiece(currentPlayer, row, col);

        // Print the board
        printBoard();

        // Check if the player won
        winner = checkWin(currentPlayer);

        // Switch to the next player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Print the winner
    if (winner != ' ')
    {
        printf("Winner: %c\n", winner);
    }
    else
    {
        printf("It's a draw.\n");
    }

    return 0;
}
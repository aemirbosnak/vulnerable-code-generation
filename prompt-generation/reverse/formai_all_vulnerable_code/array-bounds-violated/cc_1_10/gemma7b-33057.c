//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

int main()
{
    // Game board
    char board[BOARD_SIZE][BOARD_SIZE] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };

    // Player's move
    int move_row, move_col;

    // Seed the random number generator
    srand(time(NULL));

    // Computer's move
    int comp_row, comp_col;

    // Game loop
    while (!board[comp_row][comp_col] && board[move_row][move_col] != PLAYER_X)
    {
        // Get the computer's move
        comp_row = rand() % BOARD_SIZE;
        comp_col = rand() % BOARD_SIZE;

        // Place the computer's mark
        board[comp_row][comp_col] = PLAYER_O;
    }

    // Check if the player won
    if (board[move_row][move_col] == PLAYER_X)
    {
        printf("You won!");
    }
    // Check if the computer won
    else if (board[comp_row][comp_col] == PLAYER_O)
    {
        printf("Computer won!");
    }
    // It's a draw
    else
    {
        printf("Draw!");
    }

    return 0;
}
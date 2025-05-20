//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    // Game board
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY, EMPTY, EMPTY},
                                {EMPTY, EMPTY, EMPTY},
                                {EMPTY, EMPTY, EMPTY}};

    // Player's move
    int move_row, move_col;

    // Seed for random moves
    srand(time(NULL));

    // Computer's move
    int comp_row, comp_col;

    // Game loop
    while (!board[move_row][move_col] && board[comp_row][comp_col] != PLAYER_O)
    {
        // Player's turn
        printf("Enter row (1-3): ");
        scanf("%d", &move_row);

        printf("Enter column (1-3): ");
        scanf("%d", &move_col);

        // Validate move
        if (board[move_row][move_col] != EMPTY)
        {
            printf("Invalid move, try again.\n");
            continue;
        }

        // Make player's move
        board[move_row][move_col] = PLAYER_X;

        // Computer's turn
        comp_row = rand() % BOARD_SIZE;
        comp_col = rand() % BOARD_SIZE;

        // Check if move is valid
        while (board[comp_row][comp_col] != EMPTY)
        {
            comp_row = rand() % BOARD_SIZE;
            comp_col = rand() % BOARD_SIZE;
        }

        // Make computer's move
        board[comp_row][comp_col] = PLAYER_O;
    }

    // Game over
    if (board[move_row][move_col] == PLAYER_X)
    {
        printf("You win!\n");
    }
    else
    {
        printf("Computer wins!\n");
    }

    return 0;
}
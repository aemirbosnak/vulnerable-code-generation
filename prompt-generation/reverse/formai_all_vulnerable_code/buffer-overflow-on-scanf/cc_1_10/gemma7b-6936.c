//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 6
#define RED_PAWN 1
#define BLACK_PAWN 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0, 0},
                                {RED_PAWN, RED_PAWN, 0, 0, 0, 0},
                                {0, 0, 0, BLACK_PAWN, BLACK_PAWN, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0}};

    // Game loop
    while (1)
    {
        // Print the board
        for (int r = 0; r < BOARD_SIZE; r++)
        {
            for (int c = 0; c < BOARD_SIZE; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Get the player's move
        int move_row, move_col;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &move_row, &move_col);

        // Validate the move
        if (move_row < 0 || move_row >= BOARD_SIZE || move_col < 0 || move_col >= BOARD_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is valid
        if (board[move_row][move_col] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[move_row][move_col] = RED_PAWN;

        // Check if the player has won
        if (board[move_row][move_col] == RED_PAWN)
        {
            printf("You have won!\n");
            break;
        }

        // Next turn
        printf("Next turn.\n");
    }

    return 0;
}
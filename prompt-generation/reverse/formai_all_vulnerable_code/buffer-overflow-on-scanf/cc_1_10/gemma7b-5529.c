//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = {{0}};
    int player = 1;
    int game_over = 0;
    int move_row, move_col;

    // Initialize the board
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Game loop
    while (!game_over)
    {
        // Get the player's move
        printf("Enter move (row, column): ");
        scanf("%d %d", &move_row, &move_col);

        // Validate the move
        if (move_row < 0 || move_row >= MAX_SIZE)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (move_col < 0 || move_col >= MAX_SIZE)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the piece on the board
        board[move_row][move_col] = player;

        // Check if the player has won
        if (board[move_row][move_col] == player)
        {
            game_over = 1;
            printf("You have won!\n");
        }

        // Check if the board is full
        if (board[move_row][move_col] == 0)
        {
            game_over = 1;
            printf("It's a draw.\n");
        }

        // Switch players
        player *= -1;
    }

    return 0;
}
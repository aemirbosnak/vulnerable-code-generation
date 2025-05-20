//Gemma-7B DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int player = PLAYER_X;
    int game_status = 0;
    int move_count = 0;

    // Initialize the game board
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Start the game loop
    while (!game_status && move_count < 9)
    {
        // Get the player's move
        int move_row, move_col;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &move_row, &move_col);

        // Validate the move
        if (board[move_row][move_col] != 0 || move_row < 0 || move_row >= BOARD_SIZE || move_col < 0 || move_col >= BOARD_SIZE)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        board[move_row][move_col] = player;

        // Increment the move count
        move_count++;

        // Check if the player has won
        game_status = check_win(board, player);

        // If there is no winner, switch players
        if (!game_status)
        {
            player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    // End the game
    printf("Game over! The winner is: %d\n", board[0][0] == PLAYER_X ? PLAYER_X : PLAYER_O);

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player && board[r][3] == player && board[r][4] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player && board[3][c] == player && board[4][c] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player && board[4][4] == player)
    {
        return 1;
    }

    // If there has not been a winner, return 0
    return 0;
}
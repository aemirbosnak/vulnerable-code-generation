//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT -1
#define PLAYER_X 0
#define PLAYER_O 1

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                              {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                              {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT}};

    int player = PLAYER_X;
    int move_count = 0;

    // Paranoia: Check if the board is compromised.
    if (board[0][0] != EMPTY_SPOT || board[0][1] != EMPTY_SPOT)
    {
        printf("The board has been tampered with! Aborting game.");
        return 1;
    }

    // Loop until the board is full or a player wins.
    while (move_count < BOARD_SIZE * BOARD_SIZE)
    {
        // Get the player's move.
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Validate the move.
        if (move_x < 0 || move_x >= BOARD_SIZE || move_y < 0 || move_y >= BOARD_SIZE)
        {
            printf("Invalid move. Please try again.");
            continue;
        }

        // Check if the spot is empty.
        if (board[move_x][move_y] != EMPTY_SPOT)
        {
            printf("That spot is already taken. Please try again.");
            continue;
        }

        // Make the move.
        board[move_x][move_y] = player;

        // Increment the move count.
        move_count++;

        // Check if the player has won.
        if (check_win(board, player) == 1)
        {
            printf("You have won! Congratulations!");
            return 0;
        }

        // If the board is full, it's a draw.
        if (move_count == BOARD_SIZE * BOARD_SIZE)
        {
            printf("It's a draw! No winner.");
            return 0;
        }

        // Switch to the next player.
        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows.
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == player)
        {
            return 1;
        }
    }

    // Check columns.
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == player)
        {
            return 1;
        }
    }

    // Check diagonals.
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player)
    {
        return 1;
    }

    // If all else fails, it's a draw.
    return 0;
}
//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int game_state = 0;
    int move_num = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (!game_state)
    {
        // Get the player's move
        int move = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (board[move / BOARD_SIZE][move % BOARD_SIZE] == 0)
        {
            // Make the move
            board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

            // Increment the move number
            move_num++;

            // Check if the player has won
            game_state = check_win(board, player);

            // If the player has not won, switch to the next player
            if (!game_state)
            {
                player = (player == 1) ? 2 : 1;
            }
        }
    }

    // Print the winner or draw
    if (game_state == 1)
    {
        printf("Player %d won!\n", player);
    }
    else if (move_num == BOARD_SIZE * BOARD_SIZE)
    {
        printf("It's a draw!\n");
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
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

    return 0;
}
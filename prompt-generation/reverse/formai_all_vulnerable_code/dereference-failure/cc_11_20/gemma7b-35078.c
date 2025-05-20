//Gemma-7B DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 5
#define PLAYER_X 0
#define PLAYER_O 1

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0}};

    int current_player = PLAYER_X;
    int game_over = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Play the game until someone wins or it's a draw
    while (!game_over)
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // If the move is valid, place the player's piece on the board
        if (board[move_x][move_y] == 0)
        {
            board[move_x][move_y] = current_player;

            // Check if the player has won
            if (check_win(board, current_player) == 1)
            {
                game_over = 1;
            }

            // If there is no winner, switch to the next player
            else
            {
                current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        }
    }

    // Print the winner or draw message
    if (game_over == 1)
    {
        printf("Winner: %d\n", current_player);
    }
    else
    {
        printf("Draw\n");
    }

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
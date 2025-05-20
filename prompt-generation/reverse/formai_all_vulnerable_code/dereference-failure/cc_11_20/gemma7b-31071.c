//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0}};

    int player = PLAYER_X;
    int game_status = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Play until someone wins or it's a draw
    while (!game_status)
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // If the move is valid, make it
        if (board[move_x][move_y] == 0)
        {
            board[move_x][move_y] = player;

            // Check if the player has won
            game_status = check_win(board, player);

            // If the player has not won, switch to the next player
            if (!game_status)
            {
                player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        }
    }

    // Print the winner or draw message
    if (game_status == PLAYER_X)
    {
        printf("Player X has won!\n");
    }
    else if (game_status == PLAYER_O)
    {
        printf("Player O has won!\n");
    }
    else
    {
        printf("It's a draw.\n");
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return player;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player)
        {
            return player;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return player;
    }
    else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return player;
    }

    // If there has not been a win, return 0
    return 0;
}
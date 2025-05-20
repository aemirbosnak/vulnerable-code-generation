//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int move_count = 0;
    int game_over = 0;
    char symbol = 'X';

    // Seed the random number generator
    srand(time(NULL));

    // Loop until the game is over
    while (!game_over)
    {
        // Get the player's move
        int move_x = rand() % 3;
        int move_y = rand() % 3;

        // Check if the move is valid
        if (board[move_x][move_y] == 0)
        {
            // Make the move
            board[move_x][move_y] = player;

            // Increment the move count
            move_count++;

            // Check if the player has won
            if (check_win(board, player))
            {
                // Game over
                game_over = 1;
            }
            else if (move_count == 9)
            {
                // Game over
                game_over = 1;
            }
            else
            {
                // Switch to the next player
                player = (player == 1) ? 2 : 1;
            }
        }
    }

    // Print the winner or draw
    if (game_over)
    {
        if (board[0][0] == board[0][1] && board[0][0] == board[0][2] ||
            board[1][0] == board[1][1] && board[1][0] == board[1][2] ||
            board[2][0] == board[2][1] && board[2][0] == board[2][2])
        {
            printf("Player %d won!", player);
        }
        else
        {
            printf("It's a draw!");
        }
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player)
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
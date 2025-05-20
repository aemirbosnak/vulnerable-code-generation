//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2
#define EMPTY_SPACE 0

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};

    int current_player = PLAYER_X;
    int game_over = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Play until someone wins or there is a draw
    while (!game_over)
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (board[move_x][move_y] == EMPTY_SPACE)
        {
            // Make the move
            board[move_x][move_y] = current_player;

            // Check if the player has won
            if (check_win(board, current_player))
            {
                game_over = 1;
            }
            else
            {
                // Switch to the next player
                current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        }
    }

    // Print the winner or draw
    if (game_over)
    {
        printf("The winner is: ");
        if (current_player == PLAYER_X)
        {
            printf("Player X");
        }
        else if (current_player == PLAYER_O)
        {
            printf("Player O");
        }
        else
        {
            printf("It's a draw");
        }
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
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
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

    // If there has not been a win, return 0
    return 0;
}
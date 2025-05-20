//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
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

    int player = PLAYER_X;
    int game_status = EMPTY_SPACE;

    // Seed the random number generator
    srand(time(NULL));

    // Play the game until someone wins or it's a draw
    while (game_status == EMPTY_SPACE)
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // If the move is valid, make it
        if (board[move_x][move_y] == EMPTY_SPACE)
        {
            board[move_x][move_y] = player;

            // Check if the player has won
            if (check_win(board, player) == 1)
            {
                game_status = player;
            }
            // If the board is full, it's a draw
            else if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[1][0] == board[1][1] && board[1][1] == board[2][0] && board[2][1] == board[2][2] == EMPTY_SPACE)
            {
                game_status = EMPTY_SPACE;
            }
        }
    }

    // Print the winner or draw message
    switch (game_status)
    {
        case PLAYER_X:
            printf("Player X won!");
            break;
        case PLAYER_O:
            printf("Player O won!");
            break;
        case EMPTY_SPACE:
            printf("It's a draw!");
            break;
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0] == board[r][1] && board[r][1] == board[r][2] && board[r][0] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c] == board[1][c] && board[1][c] == board[2][c] && board[0][c] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == player)
    {
        return 1;
    }

    // If there has not been a win, return 0
    return 0;
}
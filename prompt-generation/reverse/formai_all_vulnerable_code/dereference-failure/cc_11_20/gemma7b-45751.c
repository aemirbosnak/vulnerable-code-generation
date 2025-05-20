//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int current_player = PLAYER_X;
    int game_won = 0;
    int move_made = 0;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Play the game until someone wins or there is a draw
    while (!game_won && move_made < BOARD_SIZE * BOARD_SIZE)
    {
        // Get the move from the player
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // If the move is valid, make it
        if (board[move_x][move_y] == 0)
        {
            board[move_x][move_y] = current_player;
            move_made++;

            // Check if the player has won
            if (check_win(board, current_player) == 1)
            {
                game_won = 1;
            }
        }

        // Switch to the next player
        current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Print the winner or draw
    if (game_won)
    {
        printf("Player %d won!\n", current_player);
    }
    else
    {
        printf("It's a draw!\n");
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

    // No win, so return 0
    return 0;
}
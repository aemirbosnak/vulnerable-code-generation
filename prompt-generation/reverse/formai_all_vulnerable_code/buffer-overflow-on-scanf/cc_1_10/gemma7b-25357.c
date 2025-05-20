//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

// Global variables
int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};

int game_state = 0;
int current_player = PLAYER_X;

void draw_board()
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int is_board_full()
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            if (board[r][c] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int check_win(int player)
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
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

void play_game()
{
    // Game loop
    while (!game_state)
    {
        draw_board();

        // Get the move
        int move_row, move_col;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &move_row, &move_col);

        // Validate the move
        if (move_row < 0 || move_row >= BOARD_SIZE || move_col < 0 || move_col >= BOARD_SIZE || board[move_row][move_col] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[move_row][move_col] = current_player;

        // Check if the player has won
        if (check_win(current_player) == 1)
        {
            game_state = 1;
            printf("You win!\n");
        }
        // Check if the board is full
        else if (is_board_full() == 1)
        {
            game_state = 1;
            printf("It's a draw.\n");
        }
        // Switch to the next player
        current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
}

int main()
{
    play_game();

    return 0;
}
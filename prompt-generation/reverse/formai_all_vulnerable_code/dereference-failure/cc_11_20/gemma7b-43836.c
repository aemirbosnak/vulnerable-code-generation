//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int size = MAX_SIZE;
    char **board = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (char *)malloc(size * sizeof(char));
    }

    int player_1_wins = 0;
    int player_2_wins = 0;
    int current_player = 1;

    // Game Loop
    while (!player_1_wins && !player_2_wins)
    {
        // Get the move
        int move_row, move_col;
        printf("Enter your move (row, column): ");
        scanf("%d, %d", &move_row, &move_col);

        // Validate the move
        if (move_row < 0 || move_row >= size || move_col < 0 || move_col >= size)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the move
        board[move_row][move_col] = current_player;

        // Check if the current player has won
        if (check_win(board, current_player))
        {
            player_1_wins = current_player == 1;
            player_2_wins = current_player == 2;
        }

        // Switch to the next player
        current_player = (current_player == 1) ? 2 : 1;
    }

    // Print the winner
    if (player_1_wins)
    {
        printf("Player 1 has won!\n");
    }
    else if (player_2_wins)
    {
        printf("Player 2 has won!\n");
    }
    else
    {
        printf("It's a draw!\n");
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}

int check_win(char **board, int current_player)
{
    // Check rows
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_SIZE; j++)
    {
        if (board[j][0] == current_player && board[j][1] == current_player && board[j][2] == current_player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player)
    {
        return 1;
    }
    else if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)
    {
        return 1;
    }

    return 0;
}
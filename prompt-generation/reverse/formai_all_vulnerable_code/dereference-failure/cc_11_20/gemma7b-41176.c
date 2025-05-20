//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int main()
{
    int size = MAX_SIZE;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    int game_over = 0;
    while (!game_over)
    {
        // Get the player's move
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        // Check if the move is valid
        if (row < 0 || row >= size || column < 0 || column >= size)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the player's mark on the board
        board[row][column] = 1;

        // Check if the player has won
        game_over = check_win(board, size);

        // If there is no winner, move to the next turn
        if (!game_over)
        {
            printf("Next turn.\n");
        }
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}

int check_win(int **board, int size)
{
    // Check rows
    for (int i = 0; i < size; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i])
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < size; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == board[j][3] && board[j][0] == board[j][4])
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] == board[4][4])
    {
        return 1;
    }

    // If there has not been a winner, return 0
    return 0;
}
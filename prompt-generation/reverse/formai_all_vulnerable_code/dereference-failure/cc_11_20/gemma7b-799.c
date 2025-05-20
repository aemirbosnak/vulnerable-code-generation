//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array to store the game board.
    int **board = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the game board.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set up the initial state of the game board.
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Simulate the game of life.
    for (int t = 0; t < 10; t++)
    {
        // Calculate the number of neighbors for each cell.
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int neighbors = 0;
                if (i > 0) neighbors++;
                if (i < 4) neighbors++;
                if (j > 0) neighbors++;
                if (j < 4) neighbors++;
                board[i][j] = neighbors;
            }
        }

        // Update the game board.
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (board[i][j] < 2 && board[i][j] > 3) board[i][j] = 0;
                else if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }

    // Print the final state of the game board.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the game board.
    for (int i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
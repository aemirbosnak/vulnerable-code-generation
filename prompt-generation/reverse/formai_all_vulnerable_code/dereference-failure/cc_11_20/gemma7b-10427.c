//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Create a spaceship
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Simulate the game
    for (int t = 0; t < 10; t++)
    {
        // Check for living cells
        for (int i = 0; i < MAX_SIZE; i++)
        {
            for (int j = 0; j < MAX_SIZE; j++)
            {
                int num_neighbors = 0;
                if (board[i-1][j] == 1) num_neighbors++;
                if (board[i+1][j] == 1) num_neighbors++;
                if (board[i][j-1] == 1) num_neighbors++;
                if (board[i][j+1] == 1) num_neighbors++;

                // Rule 1: A cell with 2 or more neighbors survives.
                if (num_neighbors >= 2) board[i][j] = 1;

                // Rule 2: An empty cell with exactly 3 neighbors becomes alive.
                else if (num_neighbors == 3) board[i][j] = 1;

                // Other cells die.
                else board[i][j] = 0;
            }
        }

        // Print the board
        for (int i = 0; i < MAX_SIZE; i++)
        {
            for (int j = 0; j < MAX_SIZE; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
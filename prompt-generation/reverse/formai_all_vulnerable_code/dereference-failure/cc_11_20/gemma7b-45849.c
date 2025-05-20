//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, columns;

    // Allocate memory for the game board
    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(columns * sizeof(int));
    }

    // Initialize the game board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            board[r][c] = 0;
        }
    }

    // Simulate game of life
    for (int t = 0; t < 10; t++)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                int neighbors = 0;
                // Check the number of neighbors
                if (r > 0) neighbors++;
                if (r < rows - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < columns - 1) neighbors++;

                // Apply the Game of Life rules
                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Print the game board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }
    }

    // Free memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}
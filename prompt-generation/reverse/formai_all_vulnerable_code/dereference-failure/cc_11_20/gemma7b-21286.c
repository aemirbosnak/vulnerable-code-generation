//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows = 5;
    int cols = 5;

    // Allocate memory for the board
    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Set some cells to 1
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Simulate the Game of Life
    int generations = 0;
    while (board[2][2] != 0)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                if (board[r - 1][c] == 1) neighbors++;
                if (board[r + 1][c] == 1) neighbors++;
                if (board[r][c - 1] == 1) neighbors++;
                if (board[r][c + 1] == 1) neighbors++;

                // Apply the Game of Life rules
                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Increment the number of generations
        generations++;

        // Print the board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Pause the program
        pause();
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>

#define MAX_ROWS 20
#define MAX_COLS 20

int main()
{
    // Create a 2D array to store the game board
    int **board = (int **)malloc(MAX_ROWS * sizeof(int *));
    for (int i = 0; i < MAX_ROWS; i++)
    {
        board[i] = (int *)malloc(MAX_COLS * sizeof(int));
    }

    // Initialize the game board
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place some initial cells
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Simulate the game of life
    int generations = 0;
    while ( generations < 10)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < MAX_ROWS; r++)
        {
            for (int c = 0; c < MAX_COLS; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < MAX_ROWS - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < MAX_COLS - 1) neighbors++;

                // Apply the game of life rules
                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Print the game board
        for (int r = 0; r < MAX_ROWS; r++)
        {
            for (int c = 0; c < MAX_COLS; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Increment the number of generations
        generations++;
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < MAX_ROWS; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENERATIONS 100

int main()
{
    int **board = NULL;
    int rows, columns;
    int generation = 0;
    int seed = time(NULL);

    // Allocate memory for the board
    board = malloc(rows * columns * sizeof(int *));
    for (int i = 0; i < rows * columns; i++)
    {
        board[i] = malloc(sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(seed);

    // Simulate the Game of Life for a number of generations
    while (generation < MAX_GENERATIONS)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                int neighbors = 0;
                // Check the cells to the north, south, east, and west
                if (r > 0) neighbors++;
                if (r < rows - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < columns - 1) neighbors++;

                // Update the cell's state
                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Increment the generation number
        generation++;
    }

    // Free the memory allocated for the board
    for (int i = 0; i < rows * columns; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
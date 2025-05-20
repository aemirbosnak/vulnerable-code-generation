//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a 2D array to store the game board
    int **board = NULL;
    int rows = 10;
    int cols = 10;
    board = (int**)malloc(rows * sizeof(int*) + rows * cols * sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the board with random values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Play the game of life
    int generations = 0;
    while (1)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int neighbors = 0;
                // Check the cells to the north, south, east, and west
                if (i > 0) neighbors++;
                if (i < rows - 1) neighbors++;
                if (j > 0) neighbors++;
                if (j < cols - 1) neighbors++;

                // Update the cell's state based on the number of neighbors
                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
                else if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
            }
        }

        // Increment the number of generations
        generations++;

        // Print the game board
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (generations > 10) break;
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < rows; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
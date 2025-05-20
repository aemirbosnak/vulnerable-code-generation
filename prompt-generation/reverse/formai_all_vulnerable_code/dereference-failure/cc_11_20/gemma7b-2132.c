//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int board_size = 0;
    int generation = 0;

    board_size = 5;
    board = malloc(board_size * sizeof(int *));
    for (int i = 0; i < board_size; i++)
    {
        board[i] = malloc(board_size * sizeof(int));
    }

    // Initialize the board with random values
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Simulate life for 10 generations
    for (generation = 0; generation < 10; generation++)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < board_size; i++)
        {
            for (int j = 0; j < board_size; j++)
            {
                int neighbors = 0;
                // Check the cells to the left
                if (j > 0)
                {
                    neighbors++;
                }
                // Check the cells above
                if (i > 0)
                {
                    neighbors++;
                }
                // Check the cells to the right
                if (j < board_size - 1)
                {
                    neighbors++;
                }
                // Check the cells below
                if (i < board_size - 1)
                {
                    neighbors++;
                }
                // Update the cell's state based on the number of neighbors
                if (board[i][j] == 1 && neighbors < 2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 0 && neighbors == 2)
                {
                    board[i][j] = 1;
                }
            }
        }

        // Print the board after each generation
        for (int i = 0; i < board_size; i++)
        {
            for (int j = 0; j < board_size; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory allocated for the board
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            free(board[i][j]);
        }
        free(board[i]);
    }
    free(board);

    return 0;
}
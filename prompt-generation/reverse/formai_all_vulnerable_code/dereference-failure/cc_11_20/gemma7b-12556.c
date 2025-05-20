//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

int main()
{
    // Allocate memory for the game board
    int **board = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int i = 0; i < MAX_CELLS; i++)
    {
        board[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Initialize the game board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            board[i][j] = 0;
        }
    }

    // Place some initial cells
    board[5][5] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Simulate the game of life
    int generations = 0;
    while (board[MAX_CELLS - 1][MAX_CELLS - 1] != 1)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                int num_neighbors = 0;
                if (i > 0) num_neighbors++;
                if (i < MAX_CELLS - 1) num_neighbors++;
                if (j > 0) num_neighbors++;
                if (j < MAX_CELLS - 1) num_neighbors++;

                // Apply the Game of Life rules
                if (board[i][j] == 1)
                {
                    if (num_neighbors < 2) board[i][j] = 0;
                    if (num_neighbors > 3) board[i][j] = 0;
                }
                else
                {
                    if (num_neighbors == 3) board[i][j] = 1;
                }
            }
        }

        // Increment the number of generations
        generations++;

        // Print the game board
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();
    }

    // Print the final game board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_CELLS; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
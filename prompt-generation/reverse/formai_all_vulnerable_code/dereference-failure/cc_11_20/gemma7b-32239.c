//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    // Create a 2D array to store the game board
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the game board with random values
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Print the game board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Calculate the number of neighbors for each cell
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            int num_neighbors = 0;
            // Check the cells to the left
            if (j > 0)
            {
                num_neighbors++;
            }
            // Check the cells above
            if (i > 0)
            {
                num_neighbors++;
            }
            // Check the cells to the right
            if (j < MAX_SIZE - 1)
            {
                num_neighbors++;
            }
            // Check the cells below
            if (i < MAX_SIZE - 1)
            {
                num_neighbors++;
            }

            // Update the cell's value based on the number of neighbors
            if (board[i][j] == 0 && num_neighbors >= 3)
            {
                board[i][j] = 1;
            }
            else if (board[i][j] == 1 && num_neighbors < 2)
            {
                board[i][j] = 0;
            }
        }
    }

    // Print the updated game board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
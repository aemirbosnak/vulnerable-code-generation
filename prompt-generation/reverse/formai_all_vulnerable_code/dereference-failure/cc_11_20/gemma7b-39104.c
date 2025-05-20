//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array to store the game board
    int **board = (int**)malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++)
    {
        board[i] = (int*)malloc(5 * sizeof(int));
    }

    // Initialize the game board with random values
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Print the game board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Calculate the number of neighbors for each cell
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int neighbors = 0;
            // Check the cell above
            if (board[i - 1][j] == 1)
            {
                neighbors++;
            }
            // Check the cell below
            if (board[i + 1][j] == 1)
            {
                neighbors++;
            }
            // Check the cell to the left
            if (board[i][j - 1] == 1)
            {
                neighbors++;
            }
            // Check the cell to the right
            if (board[i][j + 1] == 1)
            {
                neighbors++;
            }

            // Update the cell's status based on the number of neighbors
            if (board[i][j] == 0 && neighbors == 3)
            {
                board[i][j] = 1;
            }
            else if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3))
            {
                board[i][j] = 0;
            }
        }
    }

    // Print the game board after the rules have been applied
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
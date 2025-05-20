//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows = 5;
    int cols = 5;
    int generation = 0;

    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the board with random values
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Run the game for 10 generations
    for (generation = 0; generation < 10; generation++)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                // Check the cells to the left
                if (c - 1 >= 0)
                {
                    neighbors++;
                }
                // Check the cells above
                if (r - 1 >= 0)
                {
                    neighbors++;
                }
                // Check the cells below
                if (r + 1 < rows)
                {
                    neighbors++;
                }
                // Check the cells to the right
                if (c + 1 < cols)
                {
                    neighbors++;
                }

                // Apply the Game of Life rules
                if (board[r][c] == 1 && neighbors < 2)
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && neighbors == 3)
                {
                    board[r][c] = 1;
                }
            }
        }

        // Print the board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Pause the game for 2 seconds
        sleep(2);
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}
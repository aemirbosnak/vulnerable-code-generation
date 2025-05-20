//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: cheerful
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

    // Game loop
    while (generation < 10)
    {
        // Calculate the next generation
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbours = 0;
                // Check the neighbours
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            neighbours++;
                        }
                    }
                }

                // Apply the rules of survival and reproduction
                if (board[r][c] == 1 && neighbours < 2)
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && neighbours == 3)
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

        generation++;
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}
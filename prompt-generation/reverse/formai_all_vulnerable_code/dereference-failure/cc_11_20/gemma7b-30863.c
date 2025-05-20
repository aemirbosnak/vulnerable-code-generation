//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, columns;
    int generation = 0;

    // Allocate memory for the game board
    board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int *)malloc(columns * sizeof(int));
    }

    // Initialize the game board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(generation);

    // Place some random cells alive
    for (int i = 0; i < 10; i++)
    {
        board[rand() % rows][rand() % columns] = 1;
    }

    // Game loop
    while (!board[0][0] || board[rows - 1][columns - 1])
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            neighbors++;
                        }
                    }
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

        // Increment the generation number
        generation++;

        // Print the game board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Sleep for a while
        sleep(1);
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < rows; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
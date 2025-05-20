//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows = 0;
    int cols = 0;

    // Allocate memory for the game board
    board = (int**)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int *)malloc(sizeof(int) * cols);
    }

    // Initialize the game board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Set the initial state of the game board
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Run the game loop
    int generation = 0;
    while (!board[0][0] || board[rows - 1][cols - 1])
    {
        generation++;

        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                if (r - 1 >= 0) neighbors++;
                if (r + 1 < rows) neighbors++;
                if (c - 1 >= 0) neighbors++;
                if (c + 1 < cols) neighbors++;

                // Apply the Game of Life rules
                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Print the game board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Increment the generation number
        printf("Generation: %d\n", generation);
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < rows; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
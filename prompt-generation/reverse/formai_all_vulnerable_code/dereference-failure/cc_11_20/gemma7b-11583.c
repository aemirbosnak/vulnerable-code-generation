//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int **board = NULL;
    int rows = 5;
    int cols = 5;

    board = malloc(rows * cols * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        board[i] = malloc(cols * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Create a random pattern
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Simulate the game of life
    int generations = 0;
    while (board[2][2] || board[3][2] || board[2][3])
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                if (board[r - 1][c] == 1) neighbors++;
                if (board[r + 1][c] == 1) neighbors++;
                if (board[r][c - 1] == 1) neighbors++;
                if (board[r][c + 1] == 1) neighbors++;

                // Apply the rules of life
                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Increment the number of generations
        generations++;

        // Print the board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();
    }

    // Free the memory
    for (int i = 0; i < rows; i++)
    {
        free(board[i]);
    }
    free(board);

    printf("The game of life has ended after %d generations.\n", generations);

    return 0;
}
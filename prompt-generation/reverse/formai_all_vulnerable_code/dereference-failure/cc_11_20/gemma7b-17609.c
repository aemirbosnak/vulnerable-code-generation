//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdlib.h>
#include <stdio.h>

#define ROWS 20
#define COLS 20

int main()
{
    int **board = (int **)malloc(ROWS * sizeof(int *));
    for (int r = 0; r < ROWS; r++)
    {
        board[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            board[r][c] = 0;
        }
    }

    // Create some life
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Simulate generations
    int generations = 0;
    while (board[10][10] != 1)
    {
        // Calculate the next generation
        int **next_board = (int **)malloc(ROWS * sizeof(int *));
        for (int r = 0; r < ROWS; r++)
        {
            next_board[r] = (int *)malloc(COLS * sizeof(int));
        }

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                int num_neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            num_neighbors++;
                        }
                    }
                }

                next_board[r][c] = (num_neighbors == 2) || (num_neighbors == 3);
            }
        }

        // Free the old board
        for (int r = 0; r < ROWS; r++)
        {
            free(board[r]);
        }
        free(board);

        // Copy the next generation to the old board
        board = next_board;

        // Increment the generation count
        generations++;
    }

    // Print the final board
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < ROWS; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}
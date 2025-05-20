//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_GENERATIONS 20

int main()
{
    int **board = NULL;
    int board_size = 10;
    int generations = 0;

    board = (int **)malloc(board_size * sizeof(int *));
    for (int i = 0; i < board_size; i++)
    {
        board[i] = (int *)malloc(board_size * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game of Life rules
    while (generations < MAX_GENERATIONS)
    {
        for (int i = 0; i < board_size; i++)
        {
            for (int j = 0; j < board_size; j++)
            {
                int neighbors = 0;

                // Check the number of neighbors
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (r == 0 && c == 0)
                        {
                            continue;
                        }

                        if (board[i + r][j + c] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the rules
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

        generations++;
    }

    // Print the final board
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < board_size; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
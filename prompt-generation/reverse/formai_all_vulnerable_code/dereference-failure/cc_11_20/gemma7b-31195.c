//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = malloc(5 * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the board with life
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;

    // Simulate life
    int generations = 0;
    while (board[2][2] || board[2][3] || board[3][2])
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int num_neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (board[i + x][j + y] && board[i + x][j + y] != -1)
                        {
                            num_neighbors++;
                        }
                    }
                }

                // Apply the Game of Life rules
                if (board[i][j] == 1 && num_neighbors < 2)
                {
                    board[i][j] = -1;
                }
                else if (board[i][j] == 0 && num_neighbors == 3)
                {
                    board[i][j] = 1;
                }
            }
        }

        // Increment the number of generations
        generations++;

        // Print the board
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();
    }

    // Free the memory
    for (int i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
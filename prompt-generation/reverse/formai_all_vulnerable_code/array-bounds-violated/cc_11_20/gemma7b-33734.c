//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[20][20] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Seed the random number generator
    srand(time(NULL));

    // Place the initial cells randomly
    for (int i = 0; i < 10; i++)
    {
        board[rand() % 20][rand() % 20] = 1;
    }

    // Simulate life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < 20; r++)
        {
            for (int c = 0; c < 20; c++)
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

                // Apply the Game of Life rules
                if (board[r][c] == 1 && num_neighbors < 2)
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && num_neighbors == 3)
                {
                    board[r][c] = 1;
                }
            }
        }
    }

    // Print the final board
    for (int r = 0; r < 20; r++)
    {
        for (int c = 0; c < 20; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}
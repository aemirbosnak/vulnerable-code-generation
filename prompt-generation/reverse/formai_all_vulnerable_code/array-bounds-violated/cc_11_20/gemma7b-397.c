//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Seed the random number generator
    srand(time(NULL));

    // Create a random number of living cells
    int num_cells = rand() % 100;

    // Place the living cells randomly on the board
    for (int i = 0; i < num_cells; i++)
    {
        board[rand() % WIDTH][rand() % HEIGHT] = 1;
    }

    // Simulate the Game of Life for 20 generations
    for (int gen = 0; gen < 20; gen++)
    {
        // Calculate the number of living neighbors for each cell
        for (int r = 0; r < HEIGHT; r++)
        {
            for (int c = 0; c < WIDTH; c++)
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

                // Update the cell's state based on the number of living neighbors
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
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}
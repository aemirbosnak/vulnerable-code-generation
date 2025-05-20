//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    // Game board
    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Seed the random number generator
    srand(time(NULL));

    // Simulate the game of life
    for (int generation = 0; generation < 10; generation++)
    {
        // Calculate the next generation of the game board
        for (int row = 0; row < HEIGHT; row++)
        {
            for (int col = 0; col < WIDTH; col++)
            {
                int num_neighbors = 0;
                // Check the number of neighbors for each cell
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (r == 0 && c == 0) continue;
                        if (board[row + r][col + c] == 1) num_neighbors++;
                    }
                }

                // Apply the rules of survival and reproduction
                if (board[row][col] == 1)
                {
                    if (num_neighbors < 2) board[row][col] = 0;
                    else if (num_neighbors > 3) board[row][col] = 0;
                }
                else if (num_neighbors == 3) board[row][col] = 1;
            }
        }

        // Print the game board
        for (int row = 0; row < HEIGHT; row++)
        {
            for (int col = 0; col < WIDTH; col++)
            {
                printf("%d ", board[row][col]);
            }
            printf("\n");
        }
    }

    return 0;
}
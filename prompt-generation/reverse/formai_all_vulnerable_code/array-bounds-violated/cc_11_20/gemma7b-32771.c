//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: cheerful
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int x, y, seed, generation = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the initial percolating cluster
    for (seed = 0; seed < 10; seed++)
    {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
        board[x][y] = 1;
    }

    // Simulate the percolating cluster growth
    while (generation++ < 100)
    {
        for (x = 0; x < BOARD_SIZE; x++)
        {
            for (y = 0; y < BOARD_SIZE; y++)
            {
                if (board[x][y] == 0)
                {
                    int neighbors = 0;
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            if (board[x + dx][y + dy] == 1)
                            {
                                neighbors++;
                            }
                        }
                    }
                    if (neighbors > 0)
                    {
                        board[x][y] = 1;
                    }
                }
            }
        }
    }

    // Draw the percolating cluster
    for (x = 0; x < BOARD_SIZE; x++)
    {
        for (y = 0; y < BOARD_SIZE; y++)
        {
            if (board[x][y] == 1)
            {
                printf("X ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: immersive
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

#define LIFE_CELL 1
#define DEAD_CELL 0

int main()
{
    int **grid = NULL;
    int i, j, k, l;
    int seed = time(NULL);
    srand(seed);

    // Allocate memory for the grid
    grid = malloc(HEIGHT * sizeof(int *));
    for(i = 0; i < HEIGHT; i++)
    {
        grid[i] = malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            grid[i][j] = DEAD_CELL;
        }
    }

    // Randomly set some cells to life
    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            if(rand() % 2 == 0)
            {
                grid[i][j] = LIFE_CELL;
            }
        }
    }

    // Simulate life
    for(k = 0; k < 10; k++)
    {
        for(i = 0; i < HEIGHT; i++)
        {
            for(j = 0; j < WIDTH; j++)
            {
                int neighbors = 0;
                for(l = -1; l <= 1; l++)
                {
                    if(grid[i + l][j] == LIFE_CELL)
                    {
                        neighbors++;
                    }
                }

                if(grid[i][j] == LIFE_CELL && neighbors < 2)
                {
                    grid[i][j] = DEAD_CELL;
                }
                else if(grid[i][j] == DEAD_CELL && neighbors == 3)
                {
                    grid[i][j] = LIFE_CELL;
                }
            }
        }

        // Display the grid
        for(i = 0; i < HEIGHT; i++)
        {
            for(j = 0; j < WIDTH; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        printf("------------------------\n");
    }

    // Free the memory
    for(i = 0; i < HEIGHT; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
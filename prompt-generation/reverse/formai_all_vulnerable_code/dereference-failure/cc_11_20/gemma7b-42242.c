//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = NULL;
    int x, y;
    srand(time(NULL));

    // Allocate memory for the grid
    grid = malloc(WIDTH * HEIGHT * sizeof(int));
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = rand() % 2;
        }
    }

    // Simulate life
    for (int t = 0; t < 10; t++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            for (y = 0; y < HEIGHT; y++)
            {
                int neighbors = 0;
                if (x > 0) neighbors++;
                if (x < WIDTH - 1) neighbors++;
                if (y > 0) neighbors++;
                if (y < HEIGHT - 1) neighbors++;

                if (grid[x][y] == 1 && neighbors < 2) grid[x][y] = 0;
                if (grid[x][y] == 0 && neighbors == 3) grid[x][y] = 1;
            }
        }

        // Print the grid
        for (x = 0; x < WIDTH; x++)
        {
            for (y = 0; y < HEIGHT; y++)
            {
                printf("%d ", grid[x][y]);
            }
            printf("\n");
        }

        printf("--------------------------------------------\n");
    }

    // Free the memory
    free(grid);

    return 0;
}
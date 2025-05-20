//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int **grid = malloc(WIDTH * sizeof(int *)), i, j;

    for (i = 0; i < WIDTH; i++)
    {
        grid[i] = malloc(HEIGHT * sizeof(int));
    }

    srand(time(NULL));

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            int neighbors = 0;

            if (i > 0) neighbors++;
            if (i < WIDTH - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < HEIGHT - 1) neighbors++;

            if (grid[i][j] == 1 && neighbors < 2) grid[i][j] = 0;
            if (grid[i][j] == 0 && neighbors == 2) grid[i][j] = 1;
        }
    }

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < WIDTH; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
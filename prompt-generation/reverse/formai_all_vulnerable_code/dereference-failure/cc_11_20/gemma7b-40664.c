//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5
#define MAX_WATER 100

int main()
{
    int **water_map = NULL;
    int water_amount = 0;
    int x, y;

    water_map = (int**)malloc(WIDTH * sizeof(int *));
    for (x = 0; x < WIDTH; x++)
    {
        water_map[x] = (int *)malloc(HEIGHT * sizeof(int));
    }

    srand(time(NULL));

    // Fill the water map randomly
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            water_map[x][y] = rand() % MAX_WATER;
        }
    }

    // Simulate water movement
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (water_map[x][y] > 0)
            {
                // Check if the cell below is empty
                if (water_map[x][y - 1] == 0)
                {
                    // Move water to the below cell
                    water_map[x][y - 1] = water_map[x][y] / 2;
                    water_map[x][y] = water_map[x][y] % 2;
                }
            }
        }
    }

    // Print the water map
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            printf("%d ", water_map[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for (x = 0; x < WIDTH; x++)
    {
        free(water_map[x]);
    }
    free(water_map);

    return 0;
}
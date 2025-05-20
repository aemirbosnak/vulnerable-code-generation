//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 25
#define MAP_HEIGHT 25

#define CELL_SIZE 20

int main()
{
    int **map = NULL;
    int x, y;

    map = (int**)malloc(MAP_HEIGHT * sizeof(int*));
    for (x = 0; x < MAP_HEIGHT; x++)
    {
        map[x] = (int*)malloc(MAP_WIDTH * sizeof(int));
    }

    // Initialize the map with random values
    for (x = 0; x < MAP_HEIGHT; x++)
    {
        for (y = 0; y < MAP_WIDTH; y++)
        {
            map[x][y] = rand() % 2;
        }
    }

    // Percolation simulation
    for (x = 0; x < MAP_HEIGHT; x++)
    {
        for (y = 0; y < MAP_WIDTH; y++)
        {
            if (map[x][y] == 1)
            {
                // Check the four neighbors
                if (map[x - 1][y] == 1)
                {
                    map[x][y] = 2;
                }
                if (map[x + 1][y] == 1)
                {
                    map[x][y] = 2;
                }
                if (map[x][y - 1] == 1)
                {
                    map[x][y] = 2;
                }
                if (map[x][y + 1] == 1)
                {
                    map[x][y] = 2;
                }
            }
        }
    }

    // Print the final map
    for (x = 0; x < MAP_HEIGHT; x++)
    {
        for (y = 0; y < MAP_WIDTH; y++)
        {
            printf("%d ", map[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for (x = 0; x < MAP_HEIGHT; x++)
    {
        free(map[x]);
    }
    free(map);

    return 0;
}
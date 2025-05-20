//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a map
    int **map = (int **)malloc(MAP_HEIGHT * sizeof(int *));
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        map[y] = (int *)malloc(MAP_WIDTH * sizeof(int));
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            map[y][x] = 0;
        }
    }

    // Dig the maze
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (x == 0 || y == 0)
            {
                map[y][x] = 1;
            }
            else if (rand() % 2 == 0)
            {
                map[y][x] = 1;
            }
        }
    }

    // Draw the maze
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (map[y][x] == 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Free the memory
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(map[y]);
    }
    free(map);

    return 0;
}
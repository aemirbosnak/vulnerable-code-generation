//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: single-threaded
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL 1
#define EMPTY 0

int main()
{
    int **maze = NULL;
    int x, y;

    // Allocate memory for the maze
    maze = malloc(HEIGHT * sizeof(int *));
    for (y = 0; y < HEIGHT; y++)
    {
        maze[y] = malloc(WIDTH * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            maze[y][x] = EMPTY;
            if (x == 0 || y == 0 || x == WIDTH - 1 || y == HEIGHT - 1)
            {
                maze[y][x] = WALL;
            }
            else if (rand() % 2 == 0)
            {
                maze[y][x] = WALL;
            }
        }
    }

    // Print the maze
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }

    // Free the memory
    for (y = 0; y < HEIGHT; y++)
    {
        free(maze[y]);
    }
    free(maze);

    return 0;
}
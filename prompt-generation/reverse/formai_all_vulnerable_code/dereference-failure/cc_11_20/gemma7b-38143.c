//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

#define WALL 1
#define EMPTY 0

int main()
{
    int **maze = NULL;
    int x, y;

    // Allocate memory for the maze
    maze = malloc(WIDTH * HEIGHT * sizeof(int));
    if (maze == NULL)
    {
        return 1;
    }

    // Initialize the maze
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            maze[x][y] = EMPTY;
        }
    }

    // Generate the maze
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (x == 0 || y == 0 || x == WIDTH - 1 || y == HEIGHT - 1)
            {
                maze[x][y] = WALL;
            }
            else
            {
                maze[x][y] = EMPTY;
            }
        }
    }

    // Print the maze
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            printf("%d ", maze[x][y]);
        }
        printf("\n");
    }

    // Free the memory allocated for the maze
    free(maze);

    return 0;
}
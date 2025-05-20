//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

int main()
{
    int **maze = NULL;
    int x, y, i, j, seed = 123;
    srand(seed);

    // Allocate memory for the maze
    maze = (int**)malloc(HEIGHT * sizeof(int*));
    for (i = 0; i < HEIGHT; i++)
    {
        maze[i] = (int*)malloc(WIDTH * sizeof(int));
    }

    // Generate the maze
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    // Create walls
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1)
            {
                maze[i][j] = WALL;
            }
        }
    }

    // Create the path
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    maze[y][x] = PATH;

    // Print the maze
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            switch (maze[i][j])
            {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case PATH:
                    printf("O");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < HEIGHT; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}
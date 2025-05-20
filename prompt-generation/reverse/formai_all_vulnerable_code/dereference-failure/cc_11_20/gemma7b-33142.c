//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PATH 2

int main()
{
    int x, y, z;
    int **maze = (int**)malloc(HEIGHT * sizeof(int*));
    for (y = 0; y < HEIGHT; y++)
    {
        maze[y] = (int*)malloc(WIDTH * sizeof(int));
        for (x = 0; x < WIDTH; x++)
        {
            maze[y][x] = EMPTY;
        }
    }

    // Generate the maze
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (x == 0 || y == 0)
            {
                maze[y][x] = WALL;
            }
            else if (rand() % 5 == 0)
            {
                maze[y][x] = WALL;
            }
        }
    }

    // Mark the path
    maze[10][10] = PATH;

    // Print the maze
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            switch (maze[y][x])
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

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL 1
#define EMPTY 0

int main()
{
    // Create a 2D array to store the maze
    int **maze = (int **)malloc(MAZE_HEIGHT * sizeof(int *));
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        maze[i] = (int *)malloc(MAZE_WIDTH * sizeof(int));
    }

    // Generate the maze randomly
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            maze[y][x] = EMPTY;
        }
    }

    // Create a border around the maze
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            if (x == 0 || x == MAZE_WIDTH - 1)
            {
                maze[y][x] = WALL;
            }
            if (y == 0 || y == MAZE_HEIGHT - 1)
            {
                maze[y][x] = WALL;
            }
        }
    }

    // Print the maze
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            printf("%d ", maze[y][x]);
        }
        printf("\n");
    }

    // Free the memory allocated for the maze
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        free(maze[i]);
    }
    free(maze);

    return 0;
}
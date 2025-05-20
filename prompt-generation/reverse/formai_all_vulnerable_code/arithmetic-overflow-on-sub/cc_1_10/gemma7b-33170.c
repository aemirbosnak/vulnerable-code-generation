//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMaze(int x, int y, int **maze);

int main()
{
    int x, y;
    int **maze;

    printf("Enter the dimensions of the maze (in the format: x y): ");
    scanf("%d %d", &x, &y);

    maze = (int **)malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++)
    {
        maze[i] = (int *)malloc(y * sizeof(int));
    }

    generateMaze(x, y, maze);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}

void generateMaze(int x, int y, int **maze)
{
    srand(time(NULL));

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    maze[0][0] = 1;
    maze[0][y - 1] = 1;
    maze[x - 1][0] = 1;
    maze[x - 1][y - 1] = 1;
}
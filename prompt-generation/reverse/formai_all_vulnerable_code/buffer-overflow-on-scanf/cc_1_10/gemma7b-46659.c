//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define WALL 1
#define EMPTY 0

void generateMaze(int **maze, int w, int h)
{
    int i, j, r, c, n, wall_num = 0;
    srand(time(NULL));

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    n = w * h;
    for (r = 0; r < n; r++)
    {
        wall_num++;
        i = rand() % h;
        j = rand() % w;
        if (maze[i][j] == EMPTY)
        {
            maze[i][j] = WALL;
            wall_num--;
        }
    }

    wall_num = (wall_num < 50) ? wall_num : 50;
    return;
}

int main()
{
    int **maze = NULL;
    int w, h;

    printf("Enter the desired width of the maze: ");
    scanf("%d", &w);

    printf("Enter the desired height of the maze: ");
    scanf("%d", &h);

    maze = (int **)malloc(h * sizeof(int *) + h);
    for (int i = 0; i < h; i++)
    {
        maze[i] = (int *)malloc(w * sizeof(int) + w);
    }

    generateMaze(maze, w, h);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}
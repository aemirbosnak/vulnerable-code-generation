//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int x, y, i, j, maze[MAX][MAX], path[MAX][MAX], dist[MAX][MAX];

    // Initialize the maze
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            maze[i][j] = 0;
            path[i][j] = 0;
            dist[i][j] = MAX;
        }
    }

    // Create the maze
    maze[2][2] = 1;
    maze[2][3] = 1;
    maze[3][2] = 1;
    maze[3][3] = 1;
    maze[4][2] = 1;
    maze[4][3] = 1;
    maze[5][2] = 1;
    maze[5][3] = 1;

    // Find the shortest path
    dist[0][0] = 0;
    path[0][0] = 1;

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (dist[i][j] != MAX)
            {
                if (maze[i][j] == 0)
                {
                    dist[i][j] = dist[i-1][j] + 1;
                    path[i][j] = path[i-1][j] + 1;
                }
            }
        }
    }

    // Print the path
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }

    return 0;
}
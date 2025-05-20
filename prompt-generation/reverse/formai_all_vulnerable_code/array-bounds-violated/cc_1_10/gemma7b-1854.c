//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x, y, n, m, i, j, maze[10][10], path[10][10], visited[10][10];
    srand(time(NULL));

    n = 10;
    m = 10;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            maze[i][j] = rand() % 2;
            path[i][j] = -1;
            visited[i][j] = 0;
        }
    }

    x = 0;
    y = 0;

    path[x][y] = 0;
    visited[x][y] = 1;

    while (path[x][y] != -1)
    {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int r = rand() % 4;

        x += dx[r];
        y += dy[r];

        if (visited[x][y] == 0)
        {
            path[x][y] = path[x][y] + 1;
            visited[x][y] = 1;
        }
    }

    printf("The shortest path is: \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }

    return 0;
}
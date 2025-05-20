//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int maze[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
                              {1, 1, 1, 0, 0, 0, 0, 0, 1, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                              {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
                              {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int x, y;
    printf("Enter the starting position (x, y): ");
    scanf("%d %d", &x, &y);

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int found = 0;
    int visited[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX)
            continue;

        if (visited[nx][ny] == 0 && maze[nx][ny] == 1)
        {
            visited[nx][ny] = 1;
            x = nx;
            y = ny;
            if (nx == 9 && ny == 9)
                found = 1;
        }
    }

    if (found)
    {
        printf("Path found!\n");
    }
    else
    {
        printf("No path found.\n");
    }

    return 0;
}
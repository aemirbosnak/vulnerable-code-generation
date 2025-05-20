//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, x, y, a, b, found = 0;
    char **maze, **visited;

    printf("Enter the number of rows and columns in the maze: ");
    scanf("%d %d", &n, &m);

    maze = (char**)malloc(n * sizeof(char*));
    visited = (char**)malloc(n * sizeof(char*));

    for (i = 0; i < n; i++)
    {
        maze[i] = (char*)malloc(m * sizeof(char));
        visited[i] = (char*)malloc(m * sizeof(char));
    }

    printf("Enter the maze layout (0 for empty, 1 for wall, 2 for path): ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d ", &maze[i][j]);
        }
    }

    printf("Enter the starting position of the rat (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the goal position of the rat (x, y): ");
    scanf("%d %d", &a, &b);

    visited[x][y] = 1;

    while (!found)
    {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] != 1 && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;

                if (nx == a && ny == b)
                {
                    found = 1;
                }

                x = nx;
                y = ny;
            }
        }
    }

    if (found)
    {
        printf("The rat has found its way to the goal.\n");
    }
    else
    {
        printf("The rat has not found its way to the goal.\n");
    }

    return 0;
}
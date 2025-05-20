//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, m, i, j, x, y, path_x, path_y, visited[MAX][MAX], graph[MAX][MAX];

    printf("Enter the number of rows and columns in the maze: ");
    scanf("%d %d", &n, &m);

    printf("Enter the number of obstacles in the maze: ");
    scanf("%d", &x);

    printf("Enter the coordinates of the obstacles: ");
    for (i = 0; i < x; i++)
    {
        scanf("%d %d", &y, &graph[y][x]);
    }

    printf("Enter the starting point of the maze runner: ");
    scanf("%d %d", &path_x, &path_y);

    visited[path_x][path_y] = 1;

    // Algorithm to find the route in the maze
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && graph[i][j] == 0)
            {
                if (i == path_x && j == path_y)
                {
                    visited[i][j] = 1;
                }
                else
                {
                    visited[i][j] = 1;
                    if (i - 1 >= 0 && graph[i - 1][j] == 0 && visited[i - 1][j] == 0)
                    {
                        visited[i - 1][j] = 1;
                    }
                    if (i + 1 < n && graph[i + 1][j] == 0 && visited[i + 1][j] == 0)
                    {
                        visited[i + 1][j] = 1;
                    }
                    if (j - 1 >= 0 && graph[i][j - 1] == 0 && visited[i][j - 1] == 0)
                    {
                        visited[i][j - 1] = 1;
                    }
                    if (j + 1 < m && graph[i][j + 1] == 0 && visited[i][j + 1] == 0)
                    {
                        visited[i][j + 1] = 1;
                    }
                }
            }
        }
    }

    // Print the route in the maze
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (visited[i][j] == 1)
            {
                printf("%c ", '*');
            }
            else
            {
                printf("%c ", graph[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int n, m, x, y, maze[MAX][MAX], route[MAX][MAX], i, j, k;
    printf("Enter the number of rows and columns of the maze:");
    scanf("%d %d", &n, &m);

    printf("Enter the coordinates of the start and end points:");
    scanf("%d %d", &x, &y);

    printf("Enter the maze layout:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    // Calculate the route
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            route[i][j] = -1;
        }
    }

    route[x][y] = 0;

    for (k = 0; route[x][y] == -1; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (maze[i][j] == 0 && route[i][j] == -1)
                {
                    if (i == x && j == y)
                    {
                        route[i][j] = 0;
                    }
                    else
                    {
                        route[i][j] = route[x][y] + 1;
                    }
                }
            }
        }
    }

    // Print the route
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", route[i][j]);
        }
        printf("\n");
    }

    return 0;
}
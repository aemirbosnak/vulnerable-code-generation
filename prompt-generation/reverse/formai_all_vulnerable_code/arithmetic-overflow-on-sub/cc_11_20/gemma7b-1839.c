//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int x, y, i, j, n, m, visited[MAX][MAX], route[MAX][MAX];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);

    // Create the maze
    visited[n][m] = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                visited[i][j] = 1;
            }
        }
    }

    // Find the route
    route[n][m] = 1;
    for (i = n - 1; i >= 0; i--)
    {
        for (j = m - 1; j >= 0; j--)
        {
            if (visited[i][j] == 0)
            {
                route[i][j] = 1;
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
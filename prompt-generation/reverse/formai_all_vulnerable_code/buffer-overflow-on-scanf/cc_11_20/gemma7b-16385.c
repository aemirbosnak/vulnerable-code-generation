//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k, l, r;
    scanf(" %d %d ", &n, &m);
    int **graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf(" %d ", &graph[i][j]);
        }
    }
    int **visited = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        visited[i] = (int *)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            visited[i][j] = 0;
        }
    }
    int **colors = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        colors[i] = (int *)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            colors[i][j] = -1;
        }
    }
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
            {
                k = graph[i][j];
                l = colors[i][j];
                r = 0;
                for (int z = 0; z < k; z++)
                {
                    if (colors[graph[z][j]] == l)
                    {
                        r++;
                    }
                }
                if (r != 0)
                {
                    flag = 1;
                }
                visited[i][j] = 1;
                colors[i][j] = l;
            }
        }
    }
    if (flag == 0)
    {
        printf("No conflicts.\n");
    }
    else
    {
        printf("Conflicts detected.\n");
    }
    return 0;
}
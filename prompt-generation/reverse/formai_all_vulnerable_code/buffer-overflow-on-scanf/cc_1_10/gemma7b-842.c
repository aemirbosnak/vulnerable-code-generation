//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int k)
{
    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (graph[j][l] && color[j] != color[l])
                {
                    color[l] = color[j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", color[i]);
    }

    free(color);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(graph, n, k);

    return 0;
}
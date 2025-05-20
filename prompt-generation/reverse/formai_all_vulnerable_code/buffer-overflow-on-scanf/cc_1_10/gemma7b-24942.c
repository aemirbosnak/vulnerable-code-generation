//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graphColoring(int **graph, int n, int k)
{
    int **color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < k; i++)
    {
        int colorCount = 0;
        for (int j = 0; j < n; j++)
        {
            if (graph[j][i] && color[j] != -1)
            {
                colorCount++;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (graph[j][i] && colorCount == 0)
            {
                color[j] = i;
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
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(graph, n, k);

    free(graph);

    return 0;
}
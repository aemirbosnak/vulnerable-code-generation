//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n)
{
    int *color = (int *)malloc(n * sizeof(int));
    int i, j, k, flag = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && color[i] != color[j])
            {
                flag = 1;
            }
        }
    }

    if (flag == 0)
    {
        printf("Graph coloring is successful.\n");
    }
    else
    {
        printf("Graph coloring is not successful.\n");
    }

    free(color);
}

int main()
{
    int n, i, j, graph[MAX][MAX];

    printf("Enter the number of nodes:");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(graph, n);

    return 0;
}
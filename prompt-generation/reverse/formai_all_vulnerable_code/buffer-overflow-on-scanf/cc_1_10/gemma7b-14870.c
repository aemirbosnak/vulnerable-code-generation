//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int k)
{
    int *color = (int *)malloc(n * sizeof(int));
    int i, j, c, flag = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            c = graph[i][j];
            if (color[c] == color[i] || color[c] == -1)
            {
                flag = 1;
            }
        }
    }

    if (flag == 0)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", color[i] + 1);
        }
        printf("\n");
    }
    else
    {
        printf("No solution\n");
    }

    free(color);
}

int main()
{
    int **graph = (int **)malloc(MAX * sizeof(int *));
    int n, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the graph adjacency list: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d ", &graph[i][j]);
        }
    }

    graphColoring(graph, n, k);

    return 0;
}
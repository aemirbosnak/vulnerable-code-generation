//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n, int **colors)
{
    int i, j, k, color, usedColors[MAX] = {0};

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            usedColors[graph[i][j]] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        color = -1;
        for (k = 0; k < MAX; k++)
        {
            if (!usedColors[k] && color != usedColors[graph[i][0]] && color != usedColors[graph[i][1]])
            {
                color = k;
            }
        }

        colors[i] = color;
        usedColors[color] = 1;
    }
}

int main()
{
    int n, m, i, j, **graph, **colors;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    colors = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < m; i++)
    {
        scanf("Enter the source node: ");
        scanf("Enter the destination node: ");
        scanf("Enter the color of the edge: ");

        graph[graph[i][0]][graph[i][1]] = graph[i][2];
    }

    graphColoring(graph, n, colors);

    for (i = 0; i < n; i++)
    {
        printf("The color of node %d is %d\n", i + 1, colors[i]);
    }

    return 0;
}
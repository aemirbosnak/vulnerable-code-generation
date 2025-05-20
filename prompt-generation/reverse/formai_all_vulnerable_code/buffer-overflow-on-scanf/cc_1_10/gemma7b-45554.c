//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

void graph_coloring(int **graph, int n, int **color, int current_color)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_color; j++)
        {
            if (graph[i][j] && color[j] == current_color)
            {
                return;
            }
        }
        color[i] = current_color;
    }
    current_color++;
    graph_coloring(graph, n, color, current_color);
}

int main()
{
    int n, m, i, j;
    int **graph;
    int **color;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the number of edges:");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    color = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("Enter the edge (%d, %d):", &i, &j);
            graph[i][j] = 1;
        }
    }

    graph_coloring(graph, n, color, 1);

    printf("The coloring is complete.\n");

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d has color %d.\n", i, color[i]);
    }

    return 0;
}
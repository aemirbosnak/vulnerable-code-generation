//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void graph_coloring(int **graph, int n, int current_color, int *colors)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && current_color == colors[j])
            {
                return;
            }
        }
    }

    for (k = 0; k < n; k++)
    {
        if (graph[current_color][k] && colors[k] == 0)
        {
            colors[k] = current_color;
            graph_coloring(graph, n, k, colors);
            colors[k] = 0;
        }
    }
}

int main()
{
    int n, m;
    int **graph;
    int *colors;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the number of edges:");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    colors = (int *)malloc(n * sizeof(int));

    graph_coloring(graph, n, 0, colors);

    printf("The coloring is complete.\n");

    return 0;
}
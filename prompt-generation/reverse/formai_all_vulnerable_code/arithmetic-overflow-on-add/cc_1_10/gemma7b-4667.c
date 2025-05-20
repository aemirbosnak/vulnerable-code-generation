//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **color, int current_color)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && color[i] != color[j])
            {
                for (k = 0; k < MAX; k++)
                {
                    if (color[k] != color[i] && color[k] != color[j])
                    {
                        color[i] = k;
                        graph_coloring(graph, n, color, current_color + 1);
                        color[i] = MAX;
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m, i, j, current_color = 0;
    int **graph = NULL;
    int **color = NULL;

    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    color = (int *)malloc(n * sizeof(int));

    for (i = 0; i < m; i++)
    {
        scanf("Enter the source node: ", &i);
        scanf("Enter the destination node: ", &j);
        graph[i][j] = 1;
    }

    graph_coloring(graph, n, color, current_color);

    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, color[i]);
    }

    return 0;
}
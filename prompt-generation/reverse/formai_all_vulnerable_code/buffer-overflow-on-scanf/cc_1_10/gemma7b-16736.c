//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10

void graph_coloring(int **graph, int n, int **color, int current_color)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_color; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (graph[i][k] && color[k] == j)
                {
                    color[i] = -1;
                    return;
                }
            }
        }
    }

    color[current_color] = i;
    current_color++;
    graph_coloring(graph, n, color, current_color);
}

int main()
{
    int **graph = NULL;
    int n, m, current_color = 0, color[MAX_V] = { -1 };

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two vertices: ", &u, &v);
        graph[u][v] = 1;
    }

    graph_coloring(graph, n, color, current_color);

    printf("The coloring is complete.\n");

    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d is colored %d.\n", i, color[i]);
    }

    return 0;
}
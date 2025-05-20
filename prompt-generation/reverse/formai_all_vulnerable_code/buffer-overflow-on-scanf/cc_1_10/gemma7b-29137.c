//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **color, int current_color)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] && color[i] != color[j])
            {
                if (current_color == MAX - 1)
                {
                    return;
                }
                color[j] = current_color++;
                graph_coloring(graph, n, color, current_color);
            }
        }
    }
    return;
}

int main()
{
    int **graph = NULL;
    int n, m;

    printf("Enter the number of nodes: ");
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

        printf("Enter the two nodes connected by an edge: ");
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
    }

    int **color = NULL;
    color = (int *)malloc(n * sizeof(int));

    int current_color = 0;
    graph_coloring(graph, n, color, current_color);

    printf("The coloring is complete.\n");

    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d.\n", i + 1, color[i]);
    }

    return 0;
}
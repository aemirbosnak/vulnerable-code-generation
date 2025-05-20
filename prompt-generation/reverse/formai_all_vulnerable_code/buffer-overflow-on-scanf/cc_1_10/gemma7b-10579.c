//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
    int i, j, k, color, available;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && colors[i] != colors[j])
            {
                available = 0;
                for (k = 0; k < MAX; k++)
                {
                    if (available && colors[k] != colors[i] && colors[k] != colors[j])
                    {
                        colors[i] = k;
                        available = 1;
                    }
                }

                if (!available)
                {
                    printf("No solution found.\n");
                    exit(1);
                }
            }
        }
    }

    printf("Solution found.\n");
}

int main()
{
    int n, m;
    int **graph;
    int **colors;

    printf("Enter the number of nodes:** ");
    scanf("%d", &n);

    printf("Enter the number of edges:** ");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    colors = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two nodes connected by an edge: ", &u, &v);
        graph[u][v] = 1;
    }

    graph_coloring(graph, n, colors);

    return 0;
}
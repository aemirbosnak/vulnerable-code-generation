//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

int num_vertices, num_edges;

void graph_coloring()
{
    int i, j, k;

    colors[0] = 1;

    for (i = 1; i < num_vertices; i++)
    {
        colors[i] = 0;
    }

    for (i = 1; i < num_vertices; i++)
    {
        for (j = 0; j < num_vertices; j++)
        {
            if (graph[i][j] == 1 && colors[j] != 0)
            {
                colors[i] = colors[j];
            }
        }

        if (colors[i] == 0)
        {
            colors[i] = colors[i-1] + 1;
        }
    }
}

int main()
{
    int i, j, v1, v2;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_edges; i++)
    {
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &v1, &v2);

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    graph_coloring();

    printf("\nVertex\tColor\n");
    for (i = 0; i < num_vertices; i++)
    {
        printf("%d\t%d\n", i, colors[i]);
    }

    return 0;
}
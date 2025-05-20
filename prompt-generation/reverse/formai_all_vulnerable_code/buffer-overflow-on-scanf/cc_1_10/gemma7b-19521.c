//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graph_coloring(int **graph, int numVertices, int **colors)
{
    int i, j, k, color, visited = 0;

    for (i = 0; i < numVertices; i++)
    {
        visited = 0;
        for (j = 0; j < numVertices; j++)
        {
            if (graph[i][j] && colors[j] != -1)
            {
                for (k = 0; k < MAX; k++)
                {
                    if (colors[k] != -1 && colors[k] != colors[j])
                    {
                        visited = 1;
                    }
                }
            }
        }

        if (!visited)
        {
            colors[i] = color;
        }
        else
        {
            colors[i] = -1;
        }
    }
}

int main()
{
    int numVertices, numEdges;
    int **graph;
    int **colors;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    graph = (int **)malloc(numVertices * sizeof(int *));
    colors = (int *)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
        colors[i] = -1;
    }

    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        printf("Enter the two vertices connected by edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    graph_coloring(graph, numVertices, colors);

    for (int i = 0; i < numVertices; i++)
    {
        if (colors[i] != -1)
        {
            printf("Vertex %d has color %d\n", i, colors[i]);
        }
    }

    return 0;
}
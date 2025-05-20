//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graphColoring(int **graph, int nVertices, int k)
{
    int i, j, color, conflict = 0;
    int *colorArray = (int *)malloc(nVertices * sizeof(int));

    for (i = 0; i < nVertices; i++)
    {
        colorArray[i] = -1;
    }

    for (i = 0; i < nVertices; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (colorArray[graph[i][j]] != -1 && colorArray[graph[i][j]] == colorArray[i])
            {
                conflict = 1;
            }
        }
    }

    if (conflict)
    {
        printf("No solution found.\n");
    }
    else
    {
        printf("Solution found.\n");
        for (i = 0; i < nVertices; i++)
        {
            printf("Vertex %d colored with %d.\n", i, colorArray[i]);
        }
    }

    free(colorArray);
}

int main()
{
    int nVertices, nEdges, k;
    int **graph;

    printf("Enter the number of vertices:");
    scanf("%d", &nVertices);

    printf("Enter the number of edges:");
    scanf("%d", &nEdges);

    graph = (int **)malloc(nVertices * sizeof(int *));
    for (int i = 0; i < nVertices; i++)
    {
        graph[i] = (int *)malloc(nEdges * sizeof(int));
    }

    printf("Enter the adjacency list:");
    for (int i = 0; i < nEdges; i++)
    {
        scanf("%d %d", &graph[0][i], &graph[1][i]);
    }

    printf("Enter the number of colors:");
    scanf("%d", &k);

    graphColoring(graph, nVertices, k);

    return 0;
}
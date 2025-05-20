//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **graph = NULL;
    int numVertices, numEdges;

    printf("Enter the number of vertices:");
    scanf("%d", &numVertices);

    printf("Enter the number of edges:");
    scanf("%d", &numEdges);

    graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the adjacency list:");
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        scanf("%d", &u);
        scanf("%d", &v);
        graph[u][v] = 1;
    }

    int chromaticNumber = graphColoring(graph, numVertices);

    printf("The chromatic number of the graph is: %d", chromaticNumber);

    return 0;
}

int graphColoring(int **graph, int numVertices)
{
    int *color = (int *)malloc(numVertices * sizeof(int));
    int chromaticNumber = 0;

    for (int i = 0; i < numVertices; i++)
    {
        int availableColors = 0;
        for (int j = 0; j < numVertices; j++)
        {
            if (graph[i][j] && color[j] != 0)
            {
                availableColors--;
            }
        }

        color[i] = availableColors;
    }

    chromaticNumber = findMaximum(color, numVertices);

    return chromaticNumber;
}

int findMaximum(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}
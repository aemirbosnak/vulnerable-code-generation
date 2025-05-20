//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int **graph = NULL;
    int numVertices, numEdges, i, j, color, currentColor = 1, isGraphComplete = 0;
    graph = (int **)malloc(numVertices * sizeof(int *));
    for (i = 0; i < numVertices; i++)
    {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (i = 0; i < numEdges; i++)
    {
        printf("Enter the source vertex: ");
        scanf("%d", &i);

        printf("Enter the destination vertex: ");
        scanf("%d", &j);

        graph[i][j] = 1;
    }

    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            if (graph[i][j] == 1 && graph[j][i] == 1)
            {
                isGraphComplete = 1;
            }
        }
    }

    if (isGraphComplete)
    {
        printf("The graph is complete.\n");
    }
    else
    {
        printf("The graph is not complete.\n");
    }

    return 0;
}
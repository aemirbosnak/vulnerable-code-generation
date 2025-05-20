//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void graphColoring(int **graph, int n, int k)
{
    int i, j, color[n], used[k], maximum = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < k; i++)
    {
        used[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (color[graph[i][j]] == -1)
            {
                used[graph[i][j]] = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        int available = 0;

        for (j = 0; j < k; j++)
        {
            if (!used[j])
            {
                color[i] = j;
                available = 1;
            }
        }

        if (!available)
        {
            printf("No solution found.\n");
            return;
        }
    }

    printf("The optimal coloring is:\n");

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d colored with %d.\n", i + 1, color[i] + 1);
    }

    printf("The maximum number of vertices colored with the same color is %d.\n", maximum);
}

int main()
{
    int n, k;

    printf("Enter the number of vertices:** ");
    scanf("%d", &n);

    printf("Enter the number of colors:** ");
    scanf("%d", &k);

    int graph[n][MAX];

    printf("Enter the adjacency list (number of vertices, followed by the list of adjacent vertices):\n");

    for (int i = 0; i < n; i++)
    {
        graph[i][0] = 0;
        for (int j = 0; j < MAX; j++)
        {
            graph[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int numAdjacentVertices;
        scanf("%d", &numAdjacentVertices);

        for (int j = 0; j < numAdjacentVertices; j++)
        {
            int adjacentVertex;
            scanf("%d", &adjacentVertex);
            graph[i][graph[i][0]] = adjacentVertex;
            graph[i][0]++;
        }
    }

    graphColoring(graph, n, k);

    return 0;
}
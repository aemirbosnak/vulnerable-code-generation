//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_algorithm(int **graph, int numVertices)
{
    int i, j, k, currentVertex, minDistance, distance[MAX], visited[MAX] = {0};

    for (i = 0; i < numVertices; i++)
    {
        distance[i] = MAX;
    }

    distance[0] = 0;

    for (k = 0; k < numVertices; k++)
    {
        currentVertex = -1;
        minDistance = MAX;

        for (i = 0; i < numVertices; i++)
        {
            if (!visited[i] && distance[i] < minDistance)
            {
                currentVertex = i;
                minDistance = distance[i];
            }
        }

        visited[currentVertex] = 1;

        for (j = 0; j < numVertices; j++)
        {
            if (graph[currentVertex][j] && distance[currentVertex] + graph[currentVertex][j] < distance[j])
            {
                distance[j] = distance[currentVertex] + graph[currentVertex][j];
            }
        }
    }

    for (i = 0; i < numVertices; i++)
    {
        printf("Vertex %d: Distance %d\n", i, distance[i]);
    }
}

int main()
{
    int numVertices, i, j, graph[MAX][MAX];

    printf("Enter the number of vertices:");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:");
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    greedy_algorithm(graph, numVertices);

    return 0;
}
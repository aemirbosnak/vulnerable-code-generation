//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 20
#define INFINITY 999999

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES] = { 0 };
int distance[MAX_VERTICES] = { 0 };
int parent[MAX_VERTICES] = { 0 };

int minimumDistance(int vertices)
{
    int minIndex = -1;
    int min = INFINITY;
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i] && distance[i] < min)
        {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int vertices, int startVertex)
{
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        distance[i] = INFINITY;
        parent[i] = -1;
    }

    distance[startVertex] = 0;

    for (int i = 0; i < vertices - 1; i++)
    {
        int currentVertex = minimumDistance(vertices);
        visited[currentVertex] = 1;
        for (int j = 0; j < vertices; j++)
        {
            int weight = graph[currentVertex][j];
            if (weight && !visited[j] && distance[currentVertex] != INFINITY && distance[currentVertex] + weight < distance[j])
            {
                distance[j] = distance[currentVertex] + weight;
                parent[j] = currentVertex;
            }
        }
    }
}

void printPath(int vertex)
{
    if (vertex == -1)
        return;
    printPath(parent[vertex]);
    printf("%d ", vertex);
}

int main()
{
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dijkstra(vertices, startVertex);

    for (int i = 0; i < vertices; i++)
    {
        if (i == startVertex)
            continue;

        if (distance[i] == INFINITY)
            printf("There is no path from vertex %d to vertex %d\n", startVertex, i);
        else
        {
            printf("Distance from vertex %d to vertex %d is %d. Path is: ", startVertex, i, distance[i]);
            printPath(i);
            printf("\n");
        }
    }
    return 0;
}
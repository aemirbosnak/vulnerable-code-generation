//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 9

int graph[V][V] = {
    {0, 4, INF, 0, INF, INF, INF, INF, INF},
    {INF, 0, 8, INF, 0, INF, 0, INF, INF},
    {INF, INF, 0, 2, INF, 5, INF, INF, INF},
    {INF, INF, INF, 0, 1, INF, INF, 2, INF},
    {INF, INF, INF, INF, 0, 3, INF, 4, INF},
    {INF, INF, 5, INF, INF, 0, 6, INF, INF},
    {INF, 0, INF, INF, INF, INF, 0, 1, INF},
    {INF, INF, INF, 2, INF, INF, 1, 0, 7},
    {INF, INF, INF, INF, 4, INF, INF, 7, 0}
};

void printSolution(int dist[], int n)
{
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int src, int dest)
{
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++)
        dist[i] = INF, visited[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        visited[u] = 1;

        for (int v = 0; v < V; v++)

            if (!visited[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int minDistance(int dist[], int visited[])
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

int main()
{
    int source, destination;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    dijkstra(source, destination);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4
#define E 5

int graph[V][V] = { { 0, 2, INF, 0 }, { INF, 0, 3, INF }, { INF, INF, 0, 1 }, { 0, INF, INF, 0 } };

void dijkstra(int src)
{
    int dist[V];
    int visited[V];
    int u, v;

    for (int i = 0; i < V; i++)
        dist[i] = INF, visited[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        visited[u] = 1;

        for (int v = 0; v < V; v++)

            if (!visited[v] && graph[u][v] && dist[u]!= INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("\nVertex\t Distance from Source\n");

    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
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
    int start;

    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    printf("\nThe shortest distances from vertex %d are:\n", start);
    dijkstra(start);

    return 0;
}
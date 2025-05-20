//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4
#define E 5

int graph[V][V] = {
    {0, 1, INF, 10},
    {INF, 0, 5, INF},
    {INF, INF, 0, 1},
    {INF, INF, INF, 0}
};

void dijkstra(int src) {
    int dist[V];
    int visited[V];
    int i, u, v;

    for (i = 0; i < V; i++)
        dist[i] = INF, visited[i] = 0;

    dist[src] = 0;

    for (i = 0; i < V - 1; i++) {
        u = minDistance(dist, visited);

        visited[u] = 1;

        for (v = 0; v < V; v++)

            if (!visited[v] && graph[u][v] && dist[u]!= INF
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex \t Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

int main() {
    int source;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4

int graph[V][V] = { { 0, 4, INF, 0 },
                    { INF, 0, 8, INF },
                    { INF, INF, 0, 2 },
                    { 0, INF, INF, 0 } };

void dijkstra(int src) {
    int dist[V];
    int visited[V];
    int u, v;

    for (int i = 0; i < V; i++)
        dist[i] = INF, visited[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < V; i++)

            if (visited[i] == 0 && dist[i] <= min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < V; v++)

            if (!visited[v] && graph[u][v] && dist[u]!= INF
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("\nVertex\t Distance from Source\n");

    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int source;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}
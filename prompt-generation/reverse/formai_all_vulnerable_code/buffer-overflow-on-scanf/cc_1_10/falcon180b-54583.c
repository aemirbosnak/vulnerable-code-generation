//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4
#define E 6

int graph[V][V];
int dist[V];
int parent[V];
int visited[V];

void dijkstra(int spt, int dest) {
    int u, v;

    for (int i = 0; i < V; i++)
        dist[i] = INF, parent[i] = -1, visited[i] = 0;

    dist[spt] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < V; i++)
            if (visited[i] == 0 && dist[i] <= min)
                min = dist[i], u = i;

        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v], parent[v] = u;
    }

    printf("Vertex   Distance from Source\n");
    printf("---------------------------\n");

    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = { { 0, 4, INF, 0 },
                        { INF, 0, 8, 0 },
                        { INF, INF, 0, 2 },
                        { 0, INF, INF, 0 } };

    int source, destination;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    dijkstra(source, destination);

    return 0;
}
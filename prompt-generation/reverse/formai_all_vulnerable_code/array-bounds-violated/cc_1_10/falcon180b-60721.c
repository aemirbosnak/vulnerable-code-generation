//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 9999

struct Edge {
    int src, dest, weight;
};

void dijkstra(int src, int dest, struct Edge edges[], int n) {
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1, min_dist = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] <= min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && edges[u].dest == v && dist[u]!= INF && dist[u] + edges[u].weight < dist[v]) {
                dist[v] = dist[u] + edges[u].weight;
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Edge edges[n * (n - 1) / 2];

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges with their weights:\n");

    for (int i = 0; i < m; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight;
    }

    int source, destination;
    printf("Enter the source node: ");
    scanf("%d", &source);

    printf("Enter the destination node: ");
    scanf("%d", &destination);

    dijkstra(source, destination, edges, n);

    return 0;
}
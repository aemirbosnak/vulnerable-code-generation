//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX_NODES 10000
#define MAX_EDGES 1000000
#define INF INT_MAX

typedef struct {
    int to;
    int cost;
} Edge;

Edge edges[MAX_EDGES];
int num_edges;

void add_edge(int from, int to, int cost) {
    edges[num_edges] = (Edge) {.to = to,.cost = cost};
    num_edges++;
}

void dijkstra(int start, int end) {
    int dist[MAX_NODES];
    int prev[MAX_NODES];
    int visited[MAX_NODES];

    memset(dist, INF, sizeof(dist));
    memset(prev, -1, sizeof(prev));
    memset(visited, 0, sizeof(visited));

    dist[start] = 0;

    for (int i = 0; i < num_edges; i++) {
        Edge edge = edges[i];
        int u = edge.to;
        int v = edge.to;
        int cost = edge.cost;

        if (dist[u]!= INF && dist[u] + cost < dist[v]) {
            dist[v] = dist[u] + cost;
            prev[v] = u;
        }
    }

    int path_dist = dist[end];
    int path_size = 0;
    int path[MAX_NODES];

    int v = end;
    while (v!= -1) {
        path[path_size++] = v;
        v = prev[v];
    }

    printf("Shortest path: ");
    for (int i = path_size - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\nPath distance: %d\n", path_dist);
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        add_edge(from, to, cost);
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dijkstra(start, end);

    return 0;
}
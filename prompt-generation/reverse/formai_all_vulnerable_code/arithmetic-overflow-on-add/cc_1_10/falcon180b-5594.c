//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

struct Node {
    int x, y;
};

void dijkstra(struct Node* graph, int n, int start, int end) {
    int dist[n];
    int visited[n];
    int prev[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_dist = INF;
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            int weight = graph[u].x - graph[v].x + graph[u].y - graph[v].y;

            if (weight > 0 && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }
        }
    }

    printf("Shortest path from node %d to node %d:\n", start, end);
    printf("Distance: %d\n", dist[end]);

    int v = end;
    while (v!= -1) {
        printf("Node %d -> ", v);
        v = prev[v];
    }
    printf("Node %d\n", start);
}

int main() {
    struct Node graph[MAX_NODES];
    int n, m;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter coordinates for each node:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &graph[i].x, &graph[i].y);
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (node1 node2 weight):\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u].x += w;
        graph[v].x -= w;
        graph[u].y += w;
        graph[v].y -= w;
    }

    int start, end;

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("Enter ending node: ");
    scanf("%d", &end);

    dijkstra(graph, n, start, end);

    return 0;
}
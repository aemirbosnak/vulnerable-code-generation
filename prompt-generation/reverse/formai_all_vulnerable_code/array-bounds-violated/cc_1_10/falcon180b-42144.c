//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int to;
    int weight;
} Edge;

Edge graph[MAX_EDGES];
int n, m, start, end, path[MAX_NODES];

void dijkstra(int start, int end) {
    int i, u, v, dist[MAX_NODES];
    for (i = 0; i <= end; i++)
        dist[i] = INF;
    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (graph[i].to == u && graph[i].weight + dist[u] < dist[v])
                    dist[v] = graph[i].weight + dist[u];
            }
        }
    }

    printf("\nVertex\t Distance from Source\n");
    for (i = 0; i <= end; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int i, u, v, w;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the number of edges: ");
    scanf("%d", &m);

    printf("\nEnter the edges with their weights:\n");
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        graph[i].to = v;
        graph[i].weight = w;
    }

    printf("\nEnter the start node: ");
    scanf("%d", &start);

    printf("\nEnter the end node: ");
    scanf("%d", &end);

    dijkstra(start, end);

    return 0;
}
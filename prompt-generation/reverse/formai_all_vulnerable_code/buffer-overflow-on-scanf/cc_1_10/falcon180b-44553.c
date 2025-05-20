//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define INF 99999

struct Edge {
    int dest;
    int weight;
};

void dijkstra(int start, int end, struct Edge graph[MAX_EDGES]) {
    int n = 0;
    int dist[MAX_NODES];
    int prev[MAX_NODES];
    int visited[MAX_NODES];
    int u, v, i, j;

    for (i = 0; i < MAX_NODES; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < MAX_NODES - 1; i++) {
        for (j = 0; j < MAX_EDGES; j++) {
            u = graph[j].dest;
            v = graph[j].dest;

            if (dist[u]!= INF && dist[u] + graph[j].weight < dist[v]) {
                dist[v] = dist[u] + graph[j].weight;
                prev[v] = u;
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < MAX_NODES; i++) {
        if (dist[i]!= INF)
            printf("%d \t %d\n", i, dist[i]);
    }

    printf("\nPath: ");
    u = end;
    while (u!= -1) {
        printf("%d ", u);
        u = prev[u];
    }
}

int main() {
    int i, j, n, m, start, end, u, v, w;
    struct Edge graph[MAX_EDGES];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges with their weights:\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[i].dest = v;
        graph[i].weight = w;
    }

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter end node: ");
    scanf("%d", &end);

    dijkstra(start, end, graph);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 999999

typedef struct {
    int u, v, w;
} Edge;

int n, m, s, t;
Edge edges[MAX_EDGES];
int parent[MAX_NODES];
int dist[MAX_NODES];
int visited[MAX_NODES];

void init() {
    memset(parent, -1, sizeof(parent));
    memset(dist, INF, sizeof(dist));
    memset(visited, 0, sizeof(visited));
}

void bellmanFord(int start, int end) {
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dist[u]!= INF && dist[u] + edges[i].w < dist[v]) {
                    dist[v] = dist[u] + edges[i].w;
                    parent[v] = u;
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dist[u]!= INF && dist[u] + edges[i].w < dist[v]) {
                    printf("Negative cycle found!\n");
                    exit(0);
                }
            }
        }
    }

    int path[MAX_NODES];
    int pathLen = 0;

    int u = end;
    while (u!= -1) {
        path[pathLen++] = u;
        u = parent[u];
    }

    printf("Shortest path from %d to %d: ", start, end);
    for (int i = pathLen - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m);

    s = 0;
    t = n - 1;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    bellmanFord(s, t);

    return 0;
}
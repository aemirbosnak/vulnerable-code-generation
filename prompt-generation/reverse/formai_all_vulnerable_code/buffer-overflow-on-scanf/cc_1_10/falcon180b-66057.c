//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000
#define INF INT_MAX

typedef struct {
    int u, v;
    int w;
} Edge;

Edge edges[MAX_EDGES];
int n, m;
int dist[MAX_NODES];
int prev[MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int start) {
    int i, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (dist[u]!= INF && dist[u] + edges[i].w < dist[v]) {
                    dist[v] = dist[u] + edges[i].w;
                    prev[v] = u;
                }
            }
        }
    }
}

int main() {
    int i, j, u, v, w;
    srand(time(NULL));
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge) {u, v, w};
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i!= j) {
                edges[m++] = (Edge) {i, j, rand() % 100 + 1};
            }
        }
    }
    dijkstra(0);
    for (i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
    return 0;
}
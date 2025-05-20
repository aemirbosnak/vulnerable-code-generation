//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF INT_MAX

typedef struct {
    int u, v, w;
} Edge;

int n, m;
int dist[MAX_NODES];
int prev[MAX_NODES];
Edge edges[MAX_EDGES];

void dijkstra(int start) {
    int i, u, v, min_dist;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        u = -1;

        for (int j = 0; j < n; j++) {
            if (dist[j] < min_dist && prev[j]!= -1) {
                min_dist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        for (int j = 0; j < n; j++) {
            v = edges[u * n + j].v;
            if (dist[u]!= INF && dist[u] + edges[u * n + j].w < dist[v]) {
                dist[v] = dist[u] + edges[u * n + j].w;
                prev[v] = u;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge) {.u = u,.v = v,.w = w};
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dijkstra(start);

    printf("Shortest path from %d to %d: %d\n", start, end, dist[end]);

    return 0;
}
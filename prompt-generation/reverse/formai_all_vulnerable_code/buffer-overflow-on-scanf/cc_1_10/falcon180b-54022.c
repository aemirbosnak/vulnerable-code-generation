//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 0x3f3f3f3f

typedef struct {
    int u, v, w;
} Edge;

int n, m, s, t;
int dist[MAX_NODES];
int prev[MAX_NODES];
Edge edges[MAX_EDGES];

void dijkstra(int start) {
    memset(dist, 0x3f, sizeof(dist));
    memset(prev, -1, sizeof(prev));
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = -1, min_dist = INF;
        for (int j = 0; j < n; j++) {
            if (dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        if (u == -1 || u == t) break;
        for (int j = 0; j < m; j++) {
            int v = edges[j].u;
            if (v == u) v = edges[j].v;
            int new_dist = dist[u] + edges[j].w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                prev[v] = u;
            }
        }
    }
}

void print_path(int v) {
    if (v == -1) return;
    print_path(prev[v]);
    printf("%d ", v);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges[i] = (Edge){u, v, w};
    }
    scanf("%d%d", &s, &t);
    dijkstra(s);
    printf("Shortest path: ");
    print_path(t);
    printf("\nDistance: %d\n", dist[t]);
    return 0;
}
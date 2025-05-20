//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_VERTS 1000
#define MAX_EDGES 2000
#define INF 1000000

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int n, m, s, t, parent[MAX_VERTS], dist[MAX_VERTS];

void dijkstra(int start) {
    int i, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (dist[u]!= INF && dist[u] + edges[i].w < dist[v]) {
                    dist[v] = dist[u] + edges[i].w;
                    parent[v] = u;
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
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
    dijkstra(0);
    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
    return 0;
}
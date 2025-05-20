//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000
#define INF (int) 1e9

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int n, m, start, end;
int dist[MAX_NODES];
bool visited[MAX_NODES];

void dijkstra(int start) {
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;
    memset(visited, false, sizeof(visited));

    int count = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u]!= INF && dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            printf("%d is not reachable from %d\n", i, start);
        } else {
            printf("%d is reachable from %d with distance %d\n", i, start, dist[i]);
        }
    }
}

int main() {
    printf("Enter the number of nodes and edges:\n");
    scanf("%d %d", &n, &m);

    printf("Enter the edges (u, v, w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int source, destination;
    printf("Enter the source and destination nodes:\n");
    scanf("%d %d", &source, &destination);

    dijkstra(source);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define INF 1000000

typedef struct {
    int from, to, weight;
} Edge;

int n, m, s, t, u, v, w, ans;
Edge edges[MAX_EDGES];
int dist[MAX_NODES];
int prev[MAX_NODES];

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

        for (int v = 0; v < n; v++) {
            int new_dist = dist[u] + edges[u * n + v].weight;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                prev[v] = u;
            }
        }
    }
}

int main() {
    int i, j, k;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].weight);
    }

    s = 0;
    t = n - 1;

    dijkstra(s);

    printf("%d\n", dist[t]);

    return 0;
}
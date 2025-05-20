//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 1000000

int n, m, k, u, v, w, s, t;
int dist[MAX_NODES], parent[MAX_NODES], color[MAX_NODES];
int graph[MAX_NODES][MAX_NODES];

void dijkstra(int start) {
    int i, j, u, v, min_dist;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        for (j = 0; j < n; j++) {
            if (dist[j] < min_dist && color[j] == -1) {
                min_dist = dist[j];
                u = j;
            }
        }

        dist[u] = INF;

        for (j = 0; j < n; j++) {
            if (graph[u][j] && color[j] == -1 && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
                parent[j] = u;
            }
        }
    }
}

int main() {
    int i, j, u, v, w;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    scanf("%d %d", &s, &t);

    for (i = 0; i < n; i++) {
        color[i] = -1;
    }

    dijkstra(s);

    k = 1;
    color[s] = k;

    for (i = 0; i < n; i++) {
        if (color[i] == -1 && i!= s && i!= t) {
            dijkstra(i);
            k++;
        }
    }

    printf("%d\n", k);

    return 0;
}
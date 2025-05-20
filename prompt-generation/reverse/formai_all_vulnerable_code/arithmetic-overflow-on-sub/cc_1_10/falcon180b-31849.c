//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct Edge {
    int u, v, w;
} Edge;

int n, m, start, end;
Edge edges[MAX_EDGES];
int dist[MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int start) {
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_dist = INF;
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int j = 0; j < m; j++) {
            if (edges[j].u == u &&!visited[edges[j].v]) {
                int new_dist = dist[u] + edges[j].w;

                if (new_dist < dist[edges[j].v]) {
                    dist[edges[j].v] = new_dist;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    scanf("%d %d", &start, &end);

    dijkstra(start);

    printf("The shortest distance from node %d to node %d is: %d\n", start, end, dist[end]);

    return 0;
}
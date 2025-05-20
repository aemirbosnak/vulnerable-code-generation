//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

int n, m;
Edge edges[MAX_EDGES];
int dist[MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int start) {
    int i, j;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            if (dist[edges[j].src] + edges[j].weight < dist[edges[j].dest]) {
                dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;
            }
        }
    }
}

int main() {
    int i, j, u, v, w;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].src = u;
        edges[i].dest = v;
        edges[i].weight = w;
    }
    dijkstra(0);
    for (i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
    return 0;
}
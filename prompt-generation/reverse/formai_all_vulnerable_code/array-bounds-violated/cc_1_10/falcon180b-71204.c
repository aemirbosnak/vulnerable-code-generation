//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100
#define INF 1000000

int v, e, s, t;
int dist[MAX_V], parent[MAX_V];
int adj[MAX_V][MAX_V];

void dijkstra(int start) {
    int u, i, min_dist, count = 0;
    for (u = 0; u < v; u++) {
        dist[u] = INF;
        parent[u] = -1;
    }
    dist[start] = 0;
    for (u = 0; u < v - 1; u++) {
        for (i = 0; i < v; i++) {
            if (adj[u][i] && dist[u]!= INF && dist[u] + adj[u][i] < dist[i]) {
                dist[i] = dist[u] + adj[u][i];
                parent[i] = u;
            }
        }
    }
    for (u = 0; u < v; u++) {
        if (dist[u] == INF) {
            printf("\nVertex %d is not reachable from vertex %d\n", u, start);
        }
    }
}

int main() {
    int i, j, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter start vertex: ");
    scanf("%d", &s);
    printf("Enter end vertex: ");
    scanf("%d", &t);
    printf("\nEnter edges with their weights:\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &j);
        adj[u][v] = j;
        adj[v][u] = j;
    }
    dijkstra(s);
    return 0;
}
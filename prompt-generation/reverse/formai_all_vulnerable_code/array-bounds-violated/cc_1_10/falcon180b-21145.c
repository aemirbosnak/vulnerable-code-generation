//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX_V 100
#define MAX_E 200
#define INF (INT_MAX/2)

int V, E, s, t;
int adj[MAX_V][MAX_V];
int dist[MAX_V];
int parent[MAX_V];

void dijkstra(int start) {
    int u, v;
    int i, j;

    for (i = 0; i < V; ++i) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < V - 1; ++i) {
        u = -1;
        for (j = 0; j < V; ++j) {
            if (dist[j] < INF && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (u == -1)
            break;

        for (j = 0; j < V; ++j) {
            v = j;

            if (adj[u][v]!= INF && dist[u]!= INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
        }
    }
}

void print_path(int end) {
    int u = end;
    while (u!= -1) {
        printf("%d ", u);
        u = parent[u];
    }
}

int main() {
    int i, j, k, u, v, w;
    int start, end;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (i = 0; i < V; ++i) {
        for (j = 0; j < V; ++j) {
            adj[i][j] = INF;
        }
    }

    printf("Enter the edges with their weights: ");
    for (i = 0; i < E; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("The shortest path from %d to %d is: ", start, t);
    print_path(t);

    return 0;
}
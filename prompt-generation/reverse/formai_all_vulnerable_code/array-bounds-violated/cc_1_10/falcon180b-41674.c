//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000
#define MAX_V 1000
#define MAX_E 10000

int V, E, S, T;
int adj[MAX_V][MAX_V];
int dist[MAX_V];
int parent[MAX_V];
int visited[MAX_V];

void dijkstra(int s) {
    int u, v, i;
    for (u = 0; u < V; u++) {
        dist[u] = INF;
        parent[u] = -1;
    }
    dist[s] = 0;
    for (i = 0; i < V - 1; i++) {
        for (u = 0; u < V; u++) {
            for (v = 0; v < V; v++) {
                if (adj[u][v]!= INF && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

void print_path(int v) {
    if (v == -1) {
        printf("No path found.\n");
        return;
    }
    printf("Path: %d -> ", v);
    while (v!= -1) {
        printf("%d -> ", parent[v]);
        v = parent[v];
    }
    printf("%d\n", S);
}

int main() {
    int i, j, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter start vertex: ");
    scanf("%d", &S);

    printf("Enter end vertex: ");
    scanf("%d", &T);

    printf("Enter edges (u, v, w):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    dijkstra(S);

    print_path(T);

    return 0;
}
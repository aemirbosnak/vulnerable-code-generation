//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF INT_MAX

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int n, m;
int dist[MAX_NODES];
int parent[MAX_NODES];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = edges[j].u;
            v = edges[j].v;
            if (dist[u]!= INF && dist[u] + edges[j].w < dist[v]) {
                dist[v] = dist[u] + edges[j].w;
                parent[v] = u;
            }
        }
    }
}

void print_path(int end) {
    if (parent[end] == -1) {
        printf("No path found.\n");
        return;
    }
    printf("Path: ");
    int u = end;
    while (u!= -1) {
        printf("%d ", u);
        u = parent[u];
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int i, j, u, v, w;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter edge %d (u v w): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
    int start, end;
    printf("Enter the start node: ");
    scanf("%d", &start);
    printf("Enter the end node: ");
    scanf("%d", &end);
    dijkstra(start);
    print_path(end);
    return 0;
}
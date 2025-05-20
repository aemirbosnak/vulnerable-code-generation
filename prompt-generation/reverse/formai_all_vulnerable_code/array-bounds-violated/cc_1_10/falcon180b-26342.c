//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF 0x3f3f3f3f
#define MAX_V 100
#define MAX_E 1000

int v, e;
int edge[MAX_E][3] = {0};
int dist[MAX_V] = {0};
int parent[MAX_V] = {0};

void init() {
    memset(dist, INF, sizeof(dist));
    memset(parent, -1, sizeof(parent));
}

void add_edge(int u, int v, int w) {
    edge[e][0] = u;
    edge[e][1] = v;
    edge[e][2] = w;
    e++;
}

void dijkstra(int start) {
    int i, u, v;

    for (i = 0; i < v; i++) {
        dist[i] = dist[start] + edge[i][2];
        parent[i] = start;
    }

    for (i = 1; i < v; i++) {
        for (u = 0; u < v; u++) {
            for (v = 0; v < v; v++) {
                if (dist[u]!= INF && dist[u] + edge[u][v] < dist[v]) {
                    dist[v] = dist[u] + edge[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

void print_path(int end) {
    int v = end;

    if (parent[v] == -1) {
        printf("No path found.\n");
        return;
    }

    while (v!= -1) {
        printf("%d ", v);
        v = parent[v];
    }
    printf("\n");
}

int main() {
    int i, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    init();

    for (i = 0; i < e; i++) {
        printf("Enter edge %d (u v w): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &u);

    dijkstra(u);

    printf("Shortest path: ");
    print_path(parent[u]);

    return 0;
}
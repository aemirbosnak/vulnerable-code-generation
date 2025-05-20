//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF INT_MAX

typedef struct {
    int u, v, w;
} Edge;

Edge graph[MAX_EDGES];
int n, m, dist[MAX_NODES];

void init() {
    int i, j, u, v, w;
    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        graph[i].u = u;
        graph[i].v = v;
        graph[i].w = w;
    }
}

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++)
        dist[i] = INF;
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = graph[j].u;
            v = graph[j].v;
            if (dist[u]!= INF && dist[u] + graph[j].w < dist[v])
                dist[v] = dist[u] + graph[j].w;
        }
    }
}

void printSolution() {
    int i;
    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int start;
    init();
    printf("Enter the source vertex: ");
    scanf("%d", &start);
    dijkstra(start);
    printSolution();
    return 0;
}
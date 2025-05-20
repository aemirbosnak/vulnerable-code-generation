//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 0x3f3f3f3f

int n, m;
int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int prev[MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int start) {
    int i, u, v, w;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (graph[u][v]!= INF && dist[u]!= INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
    }
}

void print_path(int end) {
    int v = end;
    while (v!= -1) {
        printf("%d ", v);
        v = prev[v];
    }
    printf("\n");
}

int main() {
    int i, u, v, w;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int start, end;
    scanf("%d %d", &start, &end);
    dijkstra(start);
    printf("Shortest path: ");
    print_path(end);
    return 0;
}
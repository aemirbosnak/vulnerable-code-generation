//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 100
#define MAX_E 1000

typedef struct {
    int v, cost, next;
} Edge;

Edge graph[MAX_V][MAX_V];
int dist[MAX_V];
int n, m;

void dijkstra(int start) {
    int u, v, i, min_dist;
    for (u = 0; u < n; u++) {
        dist[u] = INF;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (dist[u]!= INF && graph[u][v].cost!= INF &&
                    (dist[u] + graph[u][v].cost) < dist[v]) {
                    dist[v] = dist[u] + graph[u][v].cost;
                }
            }
        }
    }
    printf("Vertex\t Distance from Source\n");
    for (u = 0; u < n; u++) {
        printf("%d \t %d\n", u, dist[u]);
    }
}

int main() {
    int u, v, w, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges with their weights:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v].v = v;
        graph[u][v].cost = w;
        graph[v][u].v = u;
        graph[v][u].cost = w;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &u);
    dijkstra(u);
    return 0;
}
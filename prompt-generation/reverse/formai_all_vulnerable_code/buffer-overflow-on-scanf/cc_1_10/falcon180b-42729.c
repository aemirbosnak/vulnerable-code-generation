//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 9999

int n, m;
int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int parent[MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (u = 0; u < n; u++) {
                if (graph[j][u]!= INF && dist[j]!= INF && dist[j] + graph[j][u] < dist[u]) {
                    dist[u] = dist[j] + graph[j][u];
                    parent[u] = j;
                }
            }
        }
    }
}

int main() {
    int i, j, u, v, start, end;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges (u v w): ");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &graph[u][v]);
        graph[v][u] = graph[u][v];
    }
    printf("Enter the starting node: ");
    scanf("%d", &start);
    dijkstra(start);
    printf("Enter the ending node: ");
    scanf("%d", &end);
    if (dist[end] == INF) {
        printf("There is no path from %d to %d\n", start, end);
    } else {
        printf("The shortest path from %d to %d is:\n", start, end);
        u = end;
        while (u!= -1) {
            printf("%d ", u);
            u = parent[u];
        }
    }
    return 0;
}
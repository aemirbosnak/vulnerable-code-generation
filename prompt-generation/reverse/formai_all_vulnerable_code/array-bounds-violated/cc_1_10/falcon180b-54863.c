//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_EDGES 10
#define INF 999999

int graph[MAX_NODES][MAX_EDGES];
int n, m, start, end;

int dijkstra(int start, int end) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];
    int i, j, u, v;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n; j++) {
            if (graph[j][i]!= INF && dist[j]!= INF && dist[j] + graph[j][i] < dist[i]) {
                dist[i] = dist[j] + graph[j][i];
            }
        }
    }

    return dist[end];
}

int main() {
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the start node: ");
    scanf("%d", &start);

    printf("Enter the end node: ");
    scanf("%d", &end);

    printf("Enter the graph:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    for (i = 0; i < m; i++) {
        int u, v, w;

        printf("Enter the node 1: ");
        scanf("%d", &u);

        printf("Enter the node 2: ");
        scanf("%d", &v);

        printf("Enter the weight: ");
        scanf("%d", &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int shortest_path = dijkstra(start, end);

    if (shortest_path == INF) {
        printf("There is no path from %d to %d.\n", start, end);
    } else {
        printf("The shortest path from %d to %d is %d.\n", start, end, shortest_path);
    }

    return 0;
}
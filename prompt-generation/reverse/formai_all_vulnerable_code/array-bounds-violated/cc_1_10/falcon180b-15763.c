//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct node {
    int x, y;
};

void dijkstra(struct node *graph, int n, int start, int end) {
    int dist[n];
    int prev[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        int min_dist = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int weight = graph[u].x == graph[v].x? graph[u].y - graph[v].y : graph[u].x - graph[v].x;

                if (dist[u]!= INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                }
            }
        }
    }

    printf("Shortest path from node %d to node %d:\n", start, end);
    int v = end;

    while (v!= -1) {
        printf("%d ", v);
        v = prev[v];
    }

    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct node graph[n];

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);

        graph[u].x = i;
        graph[u].y = weight;

        graph[v].x = i;
        graph[v].y = weight;
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dijkstra(graph, n, start, end);

    return 0;
}
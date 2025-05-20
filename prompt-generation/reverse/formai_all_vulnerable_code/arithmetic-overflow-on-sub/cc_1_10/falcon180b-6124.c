//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 1000000

int n, m;
int graph[MAX_NODES][MAX_EDGES];
int dist[MAX_NODES];
int visited[MAX_NODES];
int parent[MAX_NODES];

void dijkstra(int start) {
    int i, j, u, v, min_dist;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                v = graph[u][j];

                if (dist[u] + v < dist[j]) {
                    dist[j] = dist[u] + v;
                    parent[j] = u;
                }
            }
        }
    }
}

int main() {
    int i, j, u, v, w;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter the edges (u, v, w):\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][j++] = w;
        graph[v][j++] = w;
    }

    int source;
    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstra(source);

    printf("The shortest distances from node %d:\n", source);

    for (i = 0; i < n; i++) {
        if (dist[i]!= INF)
            printf("%d ", dist[i]);
        else
            printf("INF ");
    }

    printf("\n");

    return 0;
}
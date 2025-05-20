//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

int n, m;
int graph[MAX_NODES][MAX_EDGES];
int degree[MAX_NODES];

void addEdge(int u, int v, int w) {
    graph[u][degree[u]++] = v;
    graph[v][degree[v]++] = u;
}

void dijkstra(int start) {
    int i, j, u, v;
    int dist[MAX_NODES];

    for (i = 0; i < n; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (u = 0; u < degree[j]; u++) {
                v = graph[j][u];
                if (dist[j]!= INF && dist[j] + graph[j][u] < dist[v])
                    dist[v] = dist[j] + graph[j][u];
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int i, j, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges with their weights (u v w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    dijkstra(0);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 2000
#define INF 9999

int graph[MAX_NODES][MAX_EDGES];
int num_nodes, num_edges;

void add_edge(int u, int v, int w) {
    graph[u][num_edges] = v;
    graph[v][num_edges] = u;
    graph[u][num_edges + 1] = w;
    graph[v][num_edges + 1] = w;
    num_edges++;
}

void dijkstra(int start) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];
    int u, v, k;

    for (u = 0; u < num_nodes; u++) {
        dist[u] = INF;
        visited[u] = 0;
    }

    dist[start] = 0;

    for (k = 0; k < num_nodes - 1; k++) {
        int min_dist = INF;
        int u = -1;

        for (u = 0; u < num_nodes; u++) {
            if (!visited[u] && dist[u] < min_dist) {
                min_dist = dist[u];
            }
        }

        visited[u] = 1;

        for (v = 0; v < num_nodes; v++) {
            if (!visited[v]) {
                int new_dist = dist[u] + graph[u][v];

                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                }
            }
        }
    }

    printf("Node\tDistance\n");
    for (u = 0; u < num_nodes; u++) {
        printf("%d\t%d\n", u, dist[u]);
    }
}

int main() {
    int i, j, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges (u v w):\n");

    for (i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    printf("Enter the starting node: ");
    scanf("%d", &u);

    dijkstra(u);

    return 0;
}
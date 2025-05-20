//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 100
#define MAX_E 1000
#define INF INT_MAX

int V, E;
int dist[MAX_V];
int prev[MAX_V];
int adj[MAX_V][MAX_V];

void add_edge(int u, int v, int w) {
    adj[u][v] = w;
    adj[v][u] = w;
}

void dijkstra(int start) {
    int i, u, v;
    int min_dist = INF, u_min = -1;

    for (i = 0; i < V; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < V - 1; i++) {
        min_dist = INF;
        u_min = -1;

        for (u = 0; u < V; u++) {
            if (dist[u] < min_dist && u!= start) {
                min_dist = dist[u];
                u_min = u;
            }
        }

        for (v = 0; v < V; v++) {
            if (adj[u_min][v] && dist[u_min]!= INF && dist[u_min] + adj[u_min][v] < dist[v]) {
                dist[v] = dist[u_min] + adj[u_min][v];
                prev[v] = u_min;
            }
        }
    }
}

int main() {
    int i, u, v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v w):\n");

    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    printf("Vertex\t Distance from Source\n");

    for (i = 0; i < V; i++) {
        if (dist[i]!= INF)
            printf("%d \t %d\n", i, dist[i]);
    }

    return 0;
}
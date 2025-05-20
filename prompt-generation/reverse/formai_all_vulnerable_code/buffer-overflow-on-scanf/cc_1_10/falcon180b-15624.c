//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 100
#define MAX_E 100

// Graph representation
int V, E;
int adj[MAX_V][MAX_V];
int dist[MAX_V];
int parent[MAX_V];

// Initializing the graph
void init_graph() {
    int u, v, w;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &V);
    printf("\nEnter the number of edges: ");
    scanf("%d", &E);

    printf("\nEnter the edges (u, v, w):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }
}

// A* search algorithm
void a_star(int start, int end) {
    int u, v;
    int min_dist = INF;
    int min_node = -1;

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; k < V; k++) {
                if (dist[j]!= INF && dist[j] + adj[j][k] < dist[k]) {
                    dist[k] = dist[j] + adj[j][k];
                    parent[k] = j;
                }
            }
        }
    }

    printf("\nPath from %d to %d:\n", start, end);
    printf("%d", end);
    u = end;

    while (u!= -1) {
        printf(" <- %d", u);
        v = parent[u];
        u = v;
    }

    printf("\nTotal cost: %d\n", dist[end]);
}

int main() {
    init_graph();
    int start, end;

    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    printf("\nEnter the ending vertex: ");
    scanf("%d", &end);

    a_star(start, end);

    return 0;
}
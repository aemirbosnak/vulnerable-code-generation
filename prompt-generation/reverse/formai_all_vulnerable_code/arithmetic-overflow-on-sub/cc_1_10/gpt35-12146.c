//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 100000
#define INF 1e9

typedef struct Edge {
    int start;
    int end;
    int weight;
} Edge;

int dist[MAX_NODES];
int n, m;
Edge edges[MAX_EDGES];
int parent[MAX_NODES];  // to store the spannning tree

void bellman_ford(int source) {
    // initialize the distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;
    // relax edges |V| - 1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].start;
            int v = edges[j].end;
            int w = edges[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    // check for negative cycles
    for (int i = 0; i < m; i++) {
        int u = edges[i].start;
        int v = edges[i].end;
        int w = edges[i].weight;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            exit(0);
        }
    }
}

void print_path(int node) {
    if (parent[node] == -1) {
        printf("%d", node);
        return;
    }
    print_path(parent[node]);
    printf("->%d", node);
}

int main() {
    // read input graph
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &edges[i].start, &edges[i].end, &edges[i].weight);
    }
    // find shortest paths from source to all nodes
    bellman_ford(0);
    // print distances and paths
    for (int i = 0; i < n; i++) {
        printf("Distance from source to %d: %d\n", i, dist[i]);
        printf("Path from source to %d: ", i);
        print_path(i);
        printf("\n");
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTEX 100 // maximum number of vertices

typedef struct Graph {
    int V; // number of vertices
    int E; // number of edges
    int adj[MAX_VERTEX][MAX_VERTEX]; // adjacency matrix
} Graph;

void init_graph(Graph *g, int V) {
    g->V = V;
    g->E = 0;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            g->adj[i][j] = INT_MAX;
}

void add_edge(Graph *g, int src, int dest, int weight) {
    g->adj[src][dest] = weight;
    g->E++;
}

void dijkstra(Graph *g, int src, int dist[]) {
    int visited[MAX_VERTEX] = {0}; // visited vertices
    for (int i = 0; i < g->V; i++)
        dist[i] = INT_MAX; // initialize distance array
    dist[src] = 0; // distance to source vertex is 0
    for (int i = 0; i < g->V - 1; i++) {
        int u, min_dist = INT_MAX;
        // find the vertex with the minimum distance
        for (int j = 0; j < g->V; j++)
            if (!visited[j] && dist[j] < min_dist) {
                u = j;
                min_dist = dist[j];
            }
        visited[u] = 1; // mark vertex as visited
        // update distance to adjacent vertices
        for (int v = 0; v < g->V; v++)
            if (!visited[v] && g->adj[u][v] != INT_MAX && dist[u] + g->adj[u][v] < dist[v])
                dist[v] = dist[u] + g->adj[u][v];
    }
}

int main() {
    Graph g;
    int dist[MAX_VERTEX];
    int V, E; // number of vertices and edges
    scanf("%d%d", &V, &E); // read input
    init_graph(&g, V);
    // read edges and weights
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d%d%d", &src, &dest, &weight);
        add_edge(&g, src, dest, weight);
    }
    int src;
    scanf("%d", &src); // read source vertex
    dijkstra(&g, src, dist); // compute shortest distances
    // print shortest distances
    for (int i = 0; i < g.V; i++)
        printf("distance from %d to %d is %d\n", src, i, dist[i]);
    return 0;
}
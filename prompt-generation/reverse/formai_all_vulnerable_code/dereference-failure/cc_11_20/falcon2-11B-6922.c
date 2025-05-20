//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    int x, y;
    int cost;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Point *nodes;
    Edge *edges;
} Graph;

int main() {
    // Create a graph with 8 nodes and 16 edges
    Graph g = { 8, 16, NULL, NULL };

    // Create 8 nodes
    g.nodes = malloc(sizeof(Point) * g.num_nodes);
    for (int i = 0; i < g.num_nodes; i++) {
        g.nodes[i].x = rand() % 8;
        g.nodes[i].y = rand() % 8;
    }

    // Create 16 edges
    g.edges = malloc(sizeof(Edge) * g.num_edges);
    for (int i = 0; i < g.num_edges; i++) {
        Edge e = { 0, 0, 0 };
        int x1 = g.nodes[rand() % g.num_nodes].x;
        int y1 = g.nodes[rand() % g.num_nodes].y;
        int x2 = g.nodes[rand() % g.num_nodes].x;
        int y2 = g.nodes[rand() % g.num_nodes].y;
        e.x = x1;
        e.y = y1;
        e.cost = abs(x1 - x2) + abs(y1 - y2);
        g.edges[i] = e;
    }

    // Initialize the distance matrix
    int dist[g.num_nodes];
    for (int i = 0; i < g.num_nodes; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    // Dijkstra's algorithm
    for (int i = 1; i < g.num_nodes; i++) {
        int u = g.nodes[i].x + g.nodes[i].y * 8;
        int min_cost = INT_MAX;
        for (int j = 0; j < g.num_edges; j++) {
            int v = g.edges[j].x + g.edges[j].y * 8;
            if (dist[v] > dist[u] + g.edges[j].cost) {
                min_cost = dist[v] = dist[u] + g.edges[j].cost;
            }
        }
        for (int j = 0; j < g.num_edges; j++) {
            int v = g.edges[j].x + g.edges[j].y * 8;
            if (dist[v] > min_cost) {
                dist[v] = min_cost;
            }
        }
    }

    // Print the shortest path
    int prev[g.num_nodes];
    for (int i = 0; i < g.num_nodes; i++) {
        prev[i] = -1;
    }
    int curr = 0;
    for (int i = 1; i < g.num_nodes; i++) {
        if (dist[i] == dist[curr]) {
            printf("%d %d\n", g.nodes[i].x, g.nodes[i].y);
            curr = i;
        }
    }

    // Free memory
    free(g.nodes);
    free(g.edges);

    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: single-threaded
// Graph representation example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph data structure
struct graph {
    int num_vertices;
    int num_edges;
    int** edges;
};

// Add edge function
void add_edge(struct graph* g, int src, int dest) {
    g->edges[src][dest] = 1;
    g->edges[dest][src] = 1;
    g->num_edges++;
}

// Remove edge function
void remove_edge(struct graph* g, int src, int dest) {
    g->edges[src][dest] = 0;
    g->edges[dest][src] = 0;
    g->num_edges--;
}

// Print graph function
void print_graph(struct graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->edges[i][j] == 1) {
                printf("Edge from %d to %d\n", i, j);
            }
        }
    }
}

// Main function
int main() {
    // Initialize graph
    struct graph* g = malloc(sizeof(struct graph));
    g->num_vertices = 4;
    g->num_edges = 0;
    g->edges = malloc(g->num_vertices * sizeof(int*));
    for (int i = 0; i < g->num_vertices; i++) {
        g->edges[i] = malloc(g->num_vertices * sizeof(int));
        memset(g->edges[i], 0, g->num_vertices * sizeof(int));
    }

    // Add edges
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);

    // Remove edge
    remove_edge(g, 0, 2);

    // Print graph
    print_graph(g);

    // Free graph
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);

    return 0;
}
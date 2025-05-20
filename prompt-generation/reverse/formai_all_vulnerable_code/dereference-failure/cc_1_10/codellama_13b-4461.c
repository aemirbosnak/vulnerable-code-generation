//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: surprised
/*
 * Unique C Graph representation example program
 *
 * Programmer: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Graph structure
typedef struct {
    int vertex;
    int edge;
    int *adjacency;
} Graph;

// Initialize the Graph
void init_graph(Graph *g, int vertex, int edge) {
    g->vertex = vertex;
    g->edge = edge;
    g->adjacency = (int *)malloc(sizeof(int) * edge);
}

// Add an edge to the Graph
void add_edge(Graph *g, int u, int v) {
    g->adjacency[u] = v;
}

// Print the Graph
void print_graph(Graph *g) {
    int i, j;
    printf("Graph: {");
    for (i = 0; i < g->vertex; i++) {
        printf("(v%d, [", i);
        for (j = 0; j < g->edge; j++) {
            printf("%d ", g->adjacency[j]);
        }
        printf("])");
    }
    printf("}\n");
}

int main() {
    // Create a graph with 4 vertices and 5 edges
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init_graph(g, 4, 5);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);

    // Print the graph
    print_graph(g);

    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: systematic
/*
 * C Graph Representation Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct graph {
    int num_vertices;
    int num_edges;
    int** edges;
} Graph;

// Initialize graph
void init_graph(Graph* graph, int num_vertices, int num_edges) {
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->edges = malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->edges[i] = malloc(num_vertices * sizeof(int));
        memset(graph->edges[i], 0, num_vertices * sizeof(int));
    }
}

// Add edge to graph
void add_edge(Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 1;
}

// Remove edge from graph
void remove_edge(Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 0;
}

// Print graph
void print_graph(Graph* graph) {
    printf("Graph with %d vertices and %d edges:\n", graph->num_vertices, graph->num_edges);
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->edges[i][j]) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
}

// Example usage
int main() {
    Graph* graph = malloc(sizeof(Graph));
    init_graph(graph, 4, 6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 3);
    print_graph(graph);
    remove_edge(graph, 2, 3);
    print_graph(graph);
    free(graph);
    return 0;
}
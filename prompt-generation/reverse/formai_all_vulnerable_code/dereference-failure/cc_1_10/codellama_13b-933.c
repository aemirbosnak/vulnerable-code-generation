//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: romantic
// A romantic graph representation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Graph struct
struct Graph {
    int num_vertices;
    int num_edges;
    int** edges;
};

// Initialize the Graph
void init_graph(struct Graph* graph, int num_vertices, int num_edges) {
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->edges = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->edges[i] = (int*)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
}

// Add an edge to the Graph
void add_edge(struct Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 1;
}

// Remove an edge from the Graph
void remove_edge(struct Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 0;
}

// Print the Graph
void print_graph(struct Graph* graph) {
    printf("Graph (%d vertices, %d edges):\n", graph->num_vertices, graph->num_edges);
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->edges[i][j] == 1) {
                printf(" %d -- %d\n", i, j);
            }
        }
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    init_graph(graph, 5, 5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 4);
    print_graph(graph);
    remove_edge(graph, 0, 2);
    print_graph(graph);
    return 0;
}
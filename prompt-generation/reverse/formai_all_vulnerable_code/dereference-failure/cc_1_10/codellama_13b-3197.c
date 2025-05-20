//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Graph structure
typedef struct {
    int vertex_count;
    int edge_count;
    int** edges;
} Graph;

// Vertex structure
typedef struct {
    int id;
    int* edges;
    int edge_count;
} Vertex;

// Create a new graph with n vertices
Graph* create_graph(int n) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertex_count = n;
    graph->edge_count = 0;
    graph->edges = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->edges[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph->edges[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void add_edge(Graph* graph, int from, int to) {
    graph->edges[from][to] = 1;
    graph->edge_count++;
}

// Print the graph
void print_graph(Graph* graph) {
    printf("Graph with %d vertices and %d edges:\n", graph->vertex_count, graph->edge_count);
    for (int i = 0; i < graph->vertex_count; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->vertex_count; j++) {
            if (graph->edges[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a graph with 5 vertices
    Graph* graph = create_graph(5);

    // Add edges
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    return 0;
}
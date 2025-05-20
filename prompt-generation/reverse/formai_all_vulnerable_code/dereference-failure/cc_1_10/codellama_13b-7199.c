//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: synchronous
/*
 * Graph representation example program in a synchronous style
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Define a graph structure
struct graph {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
};

// Function to create a graph
struct graph* create_graph(int num_vertices, int num_edges) {
    struct graph* g = malloc(sizeof(struct graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;
    g->adjacency_matrix = malloc(num_vertices * num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->adjacency_matrix[i][j] = 0;
        }
    }
    return g;
}

// Function to add an edge to a graph
void add_edge(struct graph* g, int vertex1, int vertex2) {
    g->adjacency_matrix[vertex1][vertex2] = 1;
    g->adjacency_matrix[vertex2][vertex1] = 1;
}

// Function to remove an edge from a graph
void remove_edge(struct graph* g, int vertex1, int vertex2) {
    g->adjacency_matrix[vertex1][vertex2] = 0;
    g->adjacency_matrix[vertex2][vertex1] = 0;
}

// Function to print a graph
void print_graph(struct graph* g) {
    printf("Graph with %d vertices and %d edges:\n", g->num_vertices, g->num_edges);
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->adjacency_matrix[i][j] == 1) {
                printf("(%d, %d) ", i, j);
            }
        }
    }
    printf("\n");
}

int main() {
    // Create a graph with 4 vertices and 5 edges
    struct graph* g = create_graph(4, 5);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);

    // Print the graph
    print_graph(g);

    // Remove an edge from the graph
    remove_edge(g, 1, 3);

    // Print the graph again
    print_graph(g);

    // Free memory
    free(g->adjacency_matrix);
    free(g);

    return 0;
}
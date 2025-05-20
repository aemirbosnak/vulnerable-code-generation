//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct {
    int num_vertices;
    int *adjacency_list;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_vertices) {
    Graph* g = malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int v1, int v2) {
    g->adjacency_list[v1] = g->adjacency_list[v1] == 0 ? (int)v2 : g->adjacency_list[v1] + 1;
}

// Function to print the graph
void print_graph(Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d:", i);
        for (int j = 0; j < g->adjacency_list[i]; j++) {
            printf(" %d", g->adjacency_list[i * g->num_vertices + j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a new graph with 5 vertices
    Graph* g = create_graph(5);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Print the graph
    print_graph(g);

    // Free the graph memory
    free(g->adjacency_list);
    free(g);

    return 0;
}
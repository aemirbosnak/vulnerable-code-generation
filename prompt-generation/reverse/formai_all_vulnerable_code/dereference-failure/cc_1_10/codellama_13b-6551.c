//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: creative
// Graph representation example program

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a graph vertex
typedef struct {
    int id;
    int degree;
    int* neighbors;
} vertex;

// Define a structure for a graph
typedef struct {
    int num_vertices;
    int num_edges;
    vertex* vertices;
} graph;

// Function to create a new graph
graph* create_graph(int num_vertices) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    g->vertices = (vertex*)malloc(num_vertices * sizeof(vertex));
    for (int i = 0; i < num_vertices; i++) {
        g->vertices[i].id = i;
        g->vertices[i].degree = 0;
        g->vertices[i].neighbors = (int*)malloc(num_vertices * sizeof(int));
    }
    return g;
}

// Function to add an edge to a graph
void add_edge(graph* g, int v1, int v2) {
    g->vertices[v1].degree++;
    g->vertices[v2].degree++;
    g->vertices[v1].neighbors[g->vertices[v1].degree - 1] = v2;
    g->vertices[v2].neighbors[g->vertices[v2].degree - 1] = v1;
    g->num_edges++;
}

// Function to remove an edge from a graph
void remove_edge(graph* g, int v1, int v2) {
    g->vertices[v1].degree--;
    g->vertices[v2].degree--;
    for (int i = 0; i < g->vertices[v1].degree; i++) {
        if (g->vertices[v1].neighbors[i] == v2) {
            g->vertices[v1].neighbors[i] = g->vertices[v1].neighbors[g->vertices[v1].degree - 1];
            break;
        }
    }
    for (int i = 0; i < g->vertices[v2].degree; i++) {
        if (g->vertices[v2].neighbors[i] == v1) {
            g->vertices[v2].neighbors[i] = g->vertices[v2].neighbors[g->vertices[v2].degree - 1];
            break;
        }
    }
    g->num_edges--;
}

// Function to print a graph
void print_graph(graph* g) {
    printf("Graph:\n");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", g->vertices[i].id);
        for (int j = 0; j < g->vertices[i].degree; j++) {
            printf("%d ", g->vertices[i].neighbors[j]);
        }
        printf("\n");
    }
}

// Function to free the memory used by a graph
void free_graph(graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->vertices[i].neighbors);
    }
    free(g->vertices);
    free(g);
}

int main() {
    graph* g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    print_graph(g);
    remove_edge(g, 1, 3);
    print_graph(g);
    free_graph(g);
    return 0;
}
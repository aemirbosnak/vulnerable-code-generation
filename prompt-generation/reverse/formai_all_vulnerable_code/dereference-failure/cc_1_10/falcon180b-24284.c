//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

typedef struct Vertex {
    int id;
    int degree;
    struct Edge *edges;
} Vertex;

typedef struct Edge {
    int weight;
    Vertex *destination;
} Edge;

// Create a new vertex with the given ID
Vertex *create_vertex(int id) {
    Vertex *vertex = malloc(sizeof(Vertex));
    vertex->id = id;
    vertex->degree = 0;
    vertex->edges = NULL;
    return vertex;
}

// Create a new edge between two vertices with the given weight
Edge *create_edge(Vertex *source, Vertex *destination, int weight) {
    Edge *edge = malloc(sizeof(Edge));
    edge->weight = weight;
    edge->destination = destination;
    return edge;
}

// Add an edge to the list of edges for a vertex
void add_edge(Vertex *vertex, Edge *edge) {
    edge->destination->degree++;
    vertex->edges = realloc(vertex->edges, sizeof(Edge) * vertex->degree);
    vertex->edges[vertex->degree - 1] = *edge;
}

// Print the graph in a readable format
void print_graph(Vertex *vertices, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: ", vertices[i].id);
        Edge *edge = vertices[i].edges;
        while (edge!= NULL) {
            printf("(%d, %d) ", edge->destination->id, edge->weight);
            edge = edge->destination->edges;
        }
        printf("\n");
    }
}

// Free the memory used by the graph
void free_graph(Vertex *vertices, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        Edge *edge = vertices[i].edges;
        while (edge!= NULL) {
            free(edge);
            edge = edge->destination->edges;
        }
        free(vertices[i].edges);
        free(vertices[i].id);
    }
    free(vertices);
}

int main() {
    // Create some vertices
    Vertex *a = create_vertex(1);
    Vertex *b = create_vertex(2);
    Vertex *c = create_vertex(3);
    Vertex *d = create_vertex(4);

    // Add some edges
    add_edge(a, create_edge(a, b, 3));
    add_edge(a, create_edge(a, c, 2));
    add_edge(b, create_edge(b, d, 5));
    add_edge(c, create_edge(c, d, 1));

    // Print the graph
    print_graph(a, 4);

    // Free the memory used by the graph
    free_graph(a, 4);

    return 0;
}
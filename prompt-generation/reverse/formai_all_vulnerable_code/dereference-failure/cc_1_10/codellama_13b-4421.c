//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: creative
// Unique C Graph Representation Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a graph node
typedef struct {
    int vertex;
    int weight;
    struct node* next;
} node;

// Define structure for a graph
typedef struct {
    int num_vertices;
    int num_edges;
    struct node** adj_list;
} graph;

// Initialize graph with 0 vertices and 0 edges
graph* init_graph() {
    graph* g = malloc(sizeof(graph));
    g->num_vertices = 0;
    g->num_edges = 0;
    g->adj_list = malloc(sizeof(node*) * g->num_vertices);
    for (int i = 0; i < g->num_vertices; i++) {
        g->adj_list[i] = NULL;
    }
    return g;
}

// Add vertex to graph
void add_vertex(graph* g, int vertex) {
    g->num_vertices++;
    g->adj_list = realloc(g->adj_list, sizeof(node*) * g->num_vertices);
    g->adj_list[vertex] = NULL;
}

// Add edge to graph
void add_edge(graph* g, int start, int end, int weight) {
    node* n = malloc(sizeof(node));
    n->vertex = end;
    n->weight = weight;
    n->next = g->adj_list[start];
    g->adj_list[start] = n;
    g->num_edges++;
}

// Print graph
void print_graph(graph* g) {
    printf("Vertices: %d\n", g->num_vertices);
    printf("Edges: %d\n", g->num_edges);
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        node* n = g->adj_list[i];
        while (n != NULL) {
            printf("[%d:%d] -> ", n->vertex, n->weight);
            n = n->next;
        }
        printf("NULL\n");
    }
}

int main() {
    graph* g = init_graph();
    add_vertex(g, 0);
    add_vertex(g, 1);
    add_vertex(g, 2);
    add_vertex(g, 3);
    add_edge(g, 0, 1, 2);
    add_edge(g, 0, 2, 3);
    add_edge(g, 1, 2, 4);
    add_edge(g, 2, 3, 5);
    print_graph(g);
    return 0;
}
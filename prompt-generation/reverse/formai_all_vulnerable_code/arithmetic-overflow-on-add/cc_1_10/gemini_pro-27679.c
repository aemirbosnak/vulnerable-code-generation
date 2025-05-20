//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    char *name;
    int num_edges;
    int *edges;
} node;

typedef struct graph {
    int num_nodes;
    node *nodes;
    int num_edges;
    int **edges;
} graph;

// Create a new graph.
graph *create_graph() {
    graph *g = malloc(sizeof(graph));
    g->num_nodes = 0;
    g->nodes = NULL;
    g->num_edges = 0;
    g->edges = NULL;
    return g;
}

// Add a new node to the graph.
void add_node(graph *g, int id, char *name) {
    g->nodes = realloc(g->nodes, (g->num_nodes + 1) * sizeof(node));
    g->nodes[g->num_nodes].id = id;
    g->nodes[g->num_nodes].name = name;
    g->nodes[g->num_nodes].num_edges = 0;
    g->nodes[g->num_nodes].edges = NULL;
    g->num_nodes++;
}

// Add a new edge to the graph.
void add_edge(graph *g, int from, int to) {
    g->edges = realloc(g->edges, (g->num_edges + 1) * sizeof(int *));
    g->edges[g->num_edges] = malloc(2 * sizeof(int));
    g->edges[g->num_edges][0] = from;
    g->edges[g->num_edges][1] = to;
    g->num_edges++;
    g->nodes[from].num_edges++;
    g->nodes[from].edges = realloc(g->nodes[from].edges, g->nodes[from].num_edges * sizeof(int));
    g->nodes[from].edges[g->nodes[from].num_edges - 1] = to;
    g->nodes[to].num_edges++;
    g->nodes[to].edges = realloc(g->nodes[to].edges, g->nodes[to].num_edges * sizeof(int));
    g->nodes[to].edges[g->nodes[to].num_edges - 1] = from;
}

// Print the graph.
void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d: %s\n", g->nodes[i].id, g->nodes[i].name);
        for (int j = 0; j < g->nodes[i].num_edges; j++) {
            printf("  Edge to %d\n", g->nodes[i].edges[j]);
        }
    }
}

// Free the graph.
void free_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        free(g->nodes[i].name);
        free(g->nodes[i].edges);
    }
    free(g->nodes);
    for (int i = 0; i < g->num_edges; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);
}

// Main function.
int main() {
    // Create a new graph.
    graph *g = create_graph();

    // Add nodes to the graph.
    add_node(g, 0, "A");
    add_node(g, 1, "B");
    add_node(g, 2, "C");
    add_node(g, 3, "D");
    add_node(g, 4, "E");

    // Add edges to the graph.
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    // Print the graph.
    print_graph(g);

    // Free the graph.
    free_graph(g);

    return 0;
}
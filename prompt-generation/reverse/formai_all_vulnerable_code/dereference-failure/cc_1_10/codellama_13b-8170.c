//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Structure to represent a graph
typedef struct {
    int num_vertices;
    int num_edges;
    int* edges[MAX_EDGES];
} Graph;

// Function to add an edge to the graph
void add_edge(Graph* graph, int src, int dest) {
    graph->edges[graph->num_edges][0] = src;
    graph->edges[graph->num_edges][1] = dest;
    graph->num_edges++;
}

// Function to print the graph
void print_graph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->num_edges; j++) {
            if (graph->edges[j][0] == i) {
                printf("%d ", graph->edges[j][1]);
            }
        }
        printf("\n");
    }
}

// Function to create a graph
void create_graph(Graph* graph, int num_vertices, int num_edges) {
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
}

int main() {
    Graph graph;
    create_graph(&graph, 5, 5);
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 2, 4);
    print_graph(&graph);
    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: scalable
/*
 * graph.c
 *
 * A unique C graph representation example program in a scalable style.
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Structures used to represent a graph and its nodes.
 */
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int** edges;
} Graph;

typedef struct Node {
    int id;
    int num_neighbors;
    int* neighbors;
} Node;

/*
 * Function to create a new graph.
 */
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->edges = (int**) malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->edges[i] = (int*) malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
    return graph;
}

/*
 * Function to add an edge to a graph.
 */
void add_edge(Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 1;
    graph->num_edges++;
}

/*
 * Function to print a graph.
 */
void print_graph(Graph* graph) {
    printf("Graph with %d vertices and %d edges\n", graph->num_vertices, graph->num_edges);
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->edges[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

/*
 * Main function to test the graph.
 */
int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    print_graph(graph);
    return 0;
}
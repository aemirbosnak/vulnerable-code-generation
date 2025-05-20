//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Graph {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
} Graph;

void init_graph(Graph* graph, int num_vertices, int num_edges) {
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->adjacency_matrix = malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
}

void remove_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 0;
}

void print_graph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = malloc(sizeof(Graph));
    init_graph(graph, 5, 6);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 0);
    print_graph(graph);
    return 0;
}
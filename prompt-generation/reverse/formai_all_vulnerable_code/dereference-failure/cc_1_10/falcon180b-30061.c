//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTEX 100

// Define the structure of the graph
typedef struct {
    int num_vertices;
    char **vertices;
    int **edges;
} Graph;

// Create a new graph with the given number of vertices
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->vertices = (char**)malloc(num_vertices * sizeof(char*));
    graph->edges = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->vertices[i] = (char*)malloc(10 * sizeof(char));
        sprintf(graph->vertices[i], "V%d", i);
        graph->edges[i] = (int*)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge between two vertices in the graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->edges[vertex1][vertex2] = 1;
    graph->edges[vertex2][vertex1] = 1;
}

// Print the graph
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %s: ", graph->vertices[i]);
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->edges[i][j] == 1) {
                printf("V%d ", j);
            }
        }
        printf("\n");
    }
}

// Free the memory used by the graph
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->vertices[i]);
        free(graph->edges[i]);
    }
    free(graph->vertices);
    free(graph->edges);
    free(graph);
}

int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    free_graph(graph);
    return 0;
}
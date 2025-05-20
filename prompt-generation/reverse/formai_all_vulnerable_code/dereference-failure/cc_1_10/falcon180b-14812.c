//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_COUNT 100
#define MAX_EDGE_COUNT 1000

// Graph structure
typedef struct {
    int vertex_count;
    int *vertices;
    int edge_count;
    int **edges;
} Graph;

// Function to create a new graph
Graph *create_graph(int vertex_count) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertex_count = vertex_count;
    graph->vertices = (int *)malloc(sizeof(int) * vertex_count);
    graph->edge_count = 0;
    graph->edges = NULL;
    return graph;
}

// Function to add a vertex to the graph
void add_vertex(Graph *graph, int vertex) {
    graph->vertices[graph->vertex_count - 1] = vertex;
}

// Function to add an edge to the graph
void add_edge(Graph *graph, int vertex1, int vertex2) {
    int **edges = (int **)realloc(graph->edges, sizeof(int *) * (graph->edge_count + 1));
    edges[graph->edge_count] = (int *)malloc(sizeof(int) * 2);
    edges[graph->edge_count][0] = vertex1;
    edges[graph->edge_count][1] = vertex2;
    graph->edges = edges;
    graph->edge_count++;
}

// Function to print the graph
void print_graph(Graph *graph) {
    printf("Graph:\n");
    printf("Vertex count: %d\n", graph->vertex_count);
    for (int i = 0; i < graph->vertex_count; i++) {
        printf("Vertex %d: %d\n", i, graph->vertices[i]);
    }
    printf("Edge count: %d\n", graph->edge_count);
    for (int i = 0; i < graph->edge_count; i++) {
        printf("Edge %d: (%d, %d)\n", i, graph->edges[i][0], graph->edges[i][1]);
    }
}

// Function to free the graph memory
void free_graph(Graph *graph) {
    free(graph->vertices);
    free(graph->edges);
    free(graph);
}

// Main function
int main() {
    Graph *graph = create_graph(5);
    add_vertex(graph, 1);
    add_vertex(graph, 2);
    add_vertex(graph, 3);
    add_vertex(graph, 4);
    add_vertex(graph, 5);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    add_edge(graph, 5, 1);
    print_graph(graph);
    free_graph(graph);
    return 0;
}
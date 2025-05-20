//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
/*
 * Graph Coloring Problem Example Program
 *
 * In this example, we will use the following graph:
 *
 *   1 - 2
 *   | | |
 *   3 - 4 - 5
 *   | | |
 *   6 - 7
 *
 * We will use the following colors:
 *
 *   Red
 *   Green
 *   Blue
 *
 * The goal is to assign a color to each vertex such that no two adjacent vertices have the same color.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph vertex
typedef struct {
    int id;
    int degree;
    int* neighbors;
    int color;
} Vertex;

// Structure to represent a graph
typedef struct {
    int num_vertices;
    int num_edges;
    Vertex** vertices;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->vertices = malloc(num_vertices * sizeof(Vertex*));
    for (int i = 0; i < num_vertices; i++) {
        graph->vertices[i] = malloc(sizeof(Vertex));
        graph->vertices[i]->id = i;
        graph->vertices[i]->degree = 0;
        graph->vertices[i]->neighbors = NULL;
        graph->vertices[i]->color = 0;
    }
    return graph;
}

// Function to add an edge to a graph
void add_edge(Graph* graph, int v1, int v2) {
    graph->vertices[v1]->degree++;
    graph->vertices[v2]->degree++;
    graph->vertices[v1]->neighbors = realloc(graph->vertices[v1]->neighbors, graph->vertices[v1]->degree * sizeof(int));
    graph->vertices[v2]->neighbors = realloc(graph->vertices[v2]->neighbors, graph->vertices[v2]->degree * sizeof(int));
    graph->vertices[v1]->neighbors[graph->vertices[v1]->degree - 1] = v2;
    graph->vertices[v2]->neighbors[graph->vertices[v2]->degree - 1] = v1;
    graph->num_edges++;
}

// Function to assign colors to vertices
void color_graph(Graph* graph) {
    int num_colors = 3;
    int* colors = malloc(num_colors * sizeof(int));
    for (int i = 0; i < num_colors; i++) {
        colors[i] = i + 1;
    }
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->vertices[i]->color = colors[i % num_colors];
    }
    free(colors);
}

// Function to print the graph
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", graph->vertices[i]->id);
        for (int j = 0; j < graph->vertices[i]->degree; j++) {
            printf("%d ", graph->vertices[i]->neighbors[j]);
        }
        printf("\n");
    }
}

// Function to print the colors
void print_colors(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: %d\n", graph->vertices[i]->id, graph->vertices[i]->color);
    }
}

int main() {
    Graph* graph = create_graph(8);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 3);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 5);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    add_edge(graph, 6, 7);

    color_graph(graph);

    printf("Graph:\n");
    print_graph(graph);

    printf("\nColors:\n");
    print_colors(graph);

    return 0;
}
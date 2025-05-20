//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100
#define NO_COLOR 0

typedef struct _Graph {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int colors[MAX_VERTICES];
} Graph;

Graph *create_graph(int num_vertices) {
    Graph *graph = malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "Error: malloc failed.\n");
        return NULL;
    }

    graph->num_vertices = num_vertices;
    graph->num_edges = 0;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        graph->colors[i] = NO_COLOR;
    }

    return graph;
}

void destroy_graph(Graph *graph) {
    if (graph != NULL) {
        free(graph);
    }
}

bool add_edge(Graph *graph, int vertex1, int vertex2) {
    if (vertex1 < 0 || vertex1 >= graph->num_vertices || vertex2 < 0 || vertex2 >= graph->num_vertices) {
        fprintf(stderr, "Error: Invalid vertex.\n");
        return false;
    }

    if (graph->adj_matrix[vertex1][vertex2] == 1) {
        fprintf(stderr, "Error: Edge already exists.\n");
        return false;
    }

    graph->adj_matrix[vertex1][vertex2] = 1;
    graph->adj_matrix[vertex2][vertex1] = 1;
    graph->num_edges++;

    return true;
}

bool is_safe(Graph *graph, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex][i] == 1 && graph->colors[i] == color) {
            return false;
        }
    }

    return true;
}

bool graph_coloring(Graph *graph, int vertex) {
    if (vertex == graph->num_vertices) {
        return true;
    }

    for (int color = 1; color <= graph->num_vertices; color++) {
        if (is_safe(graph, vertex, color)) {
            graph->colors[vertex] = color;
            if (graph_coloring(graph, vertex + 1)) {
                return true;
            }
            graph->colors[vertex] = NO_COLOR;
        }
    }

    return false;
}

void print_graph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }

    printf("Vertex Colors:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d ", graph->colors[i]);
    }
    printf("\n");
}

int main() {
    Graph *graph = create_graph(4);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);

    bool result = graph_coloring(graph, 0);

    if (result) {
        print_graph(graph);
    } else {
        printf("No valid coloring exists.\n");
    }

    destroy_graph(graph);

    return 0;
}
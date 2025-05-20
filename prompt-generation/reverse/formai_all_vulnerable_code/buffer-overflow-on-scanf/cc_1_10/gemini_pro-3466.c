//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int num_vertices;
    int** adjacency_matrix;
};

struct Graph* create_graph(int num_vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_matrix = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = (int*)malloc(num_vertices * sizeof(int));
    }
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    return graph;
}

void free_graph(struct Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    free(graph);
}

bool is_safe(struct Graph* graph, int vertex, int color, int* colors) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(struct Graph* graph, int* colors, int vertex) {
    if (vertex == graph->num_vertices) {
        return true;
    }
    for (int color = 1; color <= graph->num_vertices; color++) {
        if (is_safe(graph, vertex, color, colors)) {
            colors[vertex] = color;
            if (graph_coloring(graph, colors, vertex + 1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    struct Graph* graph = create_graph(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            int edge;
            printf("Enter 1 if there is an edge between %d and %d, otherwise enter 0: ", i + 1, j + 1);
            scanf("%d", &edge);
            graph->adjacency_matrix[i][j] = edge;
        }
    }
    int* colors = (int*)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = 0;
    }
    if (graph_coloring(graph, colors, 0)) {
        printf("The graph can be colored using %d colors:\n", graph->num_vertices);
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i + 1, colors[i]);
        }
    } else {
        printf("The graph cannot be colored using %d colors.\n", graph->num_vertices);
    }
    free_graph(graph);
    free(colors);
    return 0;
}
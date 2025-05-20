//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct AdjList {
    int num_vertices;
    int *adj_matrix;
    int *color;
} AdjList;

typedef struct Vertex {
    int vertex_id;
    struct Vertex *next;
} Vertex;

AdjList *create_graph() {
    int num_vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    AdjList *graph = (AdjList *)calloc(1, sizeof(AdjList));
    graph->num_vertices = num_vertices;

    graph->adj_matrix = (int *)calloc(num_vertices * num_vertices, sizeof(int));
    graph->color = (int *)calloc(num_vertices, sizeof(int));

    for (int i = 0; i < num_vertices * num_vertices; i++) {
        graph->adj_matrix[i] = -1;
    }

    return graph;
}

void add_edge(AdjList *graph, int source, int destination) {
    graph->adj_matrix[source * graph->num_vertices + destination] = 1;
    graph->adj_matrix[destination * graph->num_vertices + source] = 1;
}

bool is_valid_color(AdjList *graph, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex * graph->num_vertices + i] == 1 && graph->color[i] == color) {
            return false;
        }
    }
    return true;
}

int graph_coloring(AdjList *graph, int vertex, int current_color) {
    if (vertex >= graph->num_vertices) {
        return 1;
    }

    for (int color = MIN_COLOR; color <= MAX_COLOR; color++) {
        if (is_valid_color(graph, vertex, color)) {
            graph->color[vertex] = color;
            for (int neighbor = 0; neighbor < graph->num_vertices; neighbor++) {
                if (graph->adj_matrix[vertex * graph->num_vertices + neighbor] == 1) {
                    int result = graph_coloring(graph, neighbor, color);
                    if (result == -1) {
                        graph->color[vertex] = -1;
                        break;
                    }
                }
            }
            if (graph->color[vertex] != -1) {
                return 1;
            }
        }
    }

    return -1;
}

void print_graph_coloring(AdjList *graph) {
    printf("\nGraph Coloring:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, graph->color[i]);
    }
}

int main() {
    AdjList *graph = create_graph();

    printf("Enter edges (source destination):\n");
    int source, destination;
    while (scanf("%d %d", &source, &destination) == 2) {
        add_edge(graph, source, destination);
    }

    int start_vertex = 0;
    int result = graph_coloring(graph, start_vertex, MIN_COLOR);

    if (result == -1) {
        printf("Graph cannot be colored with given colors.\n");
    } else {
        print_graph_coloring(graph);
    }

    free(graph->adj_matrix);
    free(graph->color);
    free(graph);

    return 0;
}
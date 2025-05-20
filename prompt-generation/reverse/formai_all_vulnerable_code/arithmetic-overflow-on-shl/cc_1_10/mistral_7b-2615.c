//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES];
    int num_vertices;
    int num_edges;
} Graph;

void add_edge(Graph *graph, int source, int destination) {
    graph->vertices[source * 2] |= (1 << destination);
    graph->vertices[destination * 2] |= (1 << source);
    graph->num_edges++;
}

bool is_valid_coloring(Graph *graph, int vertex, int color) {
    for (int neighbor = 0; neighbor < graph->num_vertices; neighbor++) {
        if (graph->vertices[vertex] & (1 << neighbor) && graph->vertices[neighbor] & (1 << color)) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(Graph *graph, int vertex, int *coloring, int max_colors) {
    if (vertex >= graph->num_vertices) {
        return true;
    }

    for (int color = 1; color <= max_colors; color++) {
        if (is_valid_coloring(graph, vertex, color)) {
            coloring[vertex] = color;
            if (graph_coloring(graph, vertex + 1, coloring, max_colors)) {
                return true;
            }
            coloring[vertex] = 0;
        }
    }
    return false;
}

void print_coloring(int *coloring, int num_vertices) {
    for (int vertex = 0; vertex < num_vertices; vertex++) {
        printf("Vertex %d: Color %d\n", vertex, coloring[vertex]);
    }
}

int main() {
    Graph graph = {};

    int num_vertices = 6;
    int num_edges = 5;

    graph.num_vertices = num_vertices;

    if (num_vertices * 2 > MAX_VERTICES || num_edges > (num_vertices * (num_vertices - 1)) / 2) {
        printf("Graph too large or not connected.\n");
        return 1;
    }

    for (int i = 0; i < num_edges; i++) {
        int source, destination;
        printf("Enter source and destination for edge %d: ", i + 1);
        scanf("%d %d", &source, &destination);
        add_edge(&graph, source, destination);
    }

    int max_colors = 3;
    int *coloring = calloc(num_vertices, sizeof(int));

    if (graph_coloring(&graph, 0, coloring, max_colors)) {
        printf("Graph colored successfully:\n");
        print_coloring(coloring, num_vertices);
    } else {
        printf("Graph cannot be colored with %d colors.\n", max_colors);
    }

    free(coloring);
    return 0;
}
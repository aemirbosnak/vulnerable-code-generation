//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void read_graph_from_file(Graph *graph, const char *filename);
bool is_valid_coloring(const Graph *graph, int coloring[], int vertex);
int backtrack(Graph *graph, int coloring[], int vertex);
void print_coloring(const int coloring[], int num_vertices);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <graph.txt>\n", argv[0]);
        return 1;
    }

    Graph graph;
    read_graph_from_file(&graph, argv[1]);

    int coloring[graph.num_vertices];
    int result = backtrack(&graph, coloring, 0);

    if (result == -1) {
        printf("No valid coloring found.\n");
    } else {
        print_coloring(coloring, graph.num_vertices);
    }

    return 0;
}

void read_graph_from_file(Graph *graph, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int num_vertices;
    fscanf(file, "%d\n", &num_vertices);
    graph->num_vertices = num_vertices;

    for (int i = 0; i < num_vertices; ++i) {
        for (int j = 0; j < num_vertices; ++j) {
            fscanf(file, "%d", &graph->adj_matrix[i][j]);
        }
    }

    fclose(file);
}

bool is_valid_coloring(const Graph *graph, int coloring[], int vertex) {
    for (int i = 0; i < graph->num_vertices; ++i) {
        if (graph->adj_matrix[vertex][i] != 0 && coloring[i] == coloring[vertex]) {
            return false;
        }
    }

    return true;
}

int backtrack(Graph *graph, int coloring[], int vertex) {
    if (vertex == graph->num_vertices) {
        return 1;
    }

    for (int color = MIN_COLOR; color <= MAX_COLOR; ++color) {
        if (is_valid_coloring(graph, coloring, vertex)) {
            coloring[vertex] = color;
            int result = backtrack(graph, coloring, vertex + 1);
            if (result != -1) {
                return result;
            }
            coloring[vertex] = -1; // Backtrack
        }
    }

    return -1;
}

void print_coloring(const int coloring[], int num_vertices) {
    printf("Coloring:\n");
    for (int i = 0; i < num_vertices; ++i) {
        printf("Vertex %d: Color %d\n", i, coloring[i] + 1);
    }
}
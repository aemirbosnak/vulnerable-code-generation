//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void read_adj_matrix_from_file(const char *filename, Graph *graph) {
    FILE *file = fopen(filename, "r");

    fscanf(file, "%d", &graph->num_vertices);

    for (int i = 0; i < graph->num_vertices; ++i) {
        for (int j = 0; j < graph->num_vertices; ++j) {
            fscanf(file, "%d", &graph->adj_matrix[i][j]);
        }
    }

    fclose(file);
}

void print_graph(const Graph *graph) {
    for (int i = 0; i < graph->num_vertices; ++i) {
        for (int j = 0; j < graph->num_vertices; ++j) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void dfs_helper(int vertex, Graph *graph, int *visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->num_vertices; ++i) {
        if (graph->adj_matrix[vertex][i] && !visited[i]) {
            dfs_helper(i, graph, visited);
        }
    }
}

void dfs(Graph *graph) {
    int *visited = calloc(graph->num_vertices, sizeof(int));

    for (int i = 0; i < graph->num_vertices; ++i) {
        if (!visited[i]) {
            dfs_helper(i, graph, visited);
            printf("\n");
        }
    }

    free(visited);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Graph graph;
    read_adj_matrix_from_file(argv[1], &graph);

    printf("Adjacency matrix:\n");
    print_graph(&graph);

    printf("Depth-first search:\n");
    dfs(&graph);

    return 0;
}
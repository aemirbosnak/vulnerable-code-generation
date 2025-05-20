//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int num_vertices;
    int num_edges;
    int** edges;
    int* colors;
} Graph;

bool is_safe(Graph* graph, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->edges[vertex][i] == 1 && graph->colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(Graph* graph, int vertex, int color) {
    if (vertex == graph->num_vertices) {
        return true;
    }
    for (int i = 0; i < MAX_COLORS; i++) {
        if (is_safe(graph, vertex, i)) {
            graph->colors[vertex] = i;
            if (graph_coloring(graph, vertex + 1, color)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int num_vertices, num_edges;
    scanf("%d %d", &num_vertices, &num_edges);
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->edges = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->edges[i] = (int*)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
    graph->colors = (int*)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        graph->colors[i] = 0;
    }
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph->edges[u][v] = graph->edges[v][u] = 1;
    }
    if (graph_coloring(graph, 0, 0)) {
        printf("Graph is colored using %d colors.\n", MAX_COLORS);
    } else {
        printf("Graph is not colored using %d colors.\n", MAX_COLORS);
    }
    free(graph->edges);
    free(graph->colors);
    free(graph);
    return 0;
}
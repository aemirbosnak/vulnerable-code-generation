//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct Graph {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

bool is_valid_color(int color, int vertex, int *colors) {
    for (int i = 0; i < vertex; i++) {
        if (colors[i] == color && i != vertex) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(Graph *graph, int *colors, int num_colors) {
    if (graph->num_vertices == 0) {
        return true;
    }

    for (int i = 0; i < num_colors; i++) {
        colors[graph->num_vertices - 1] = i;
        for (int j = 0; j < graph->num_vertices; j++) {
            if (i == colors[j] || graph->adj_matrix[j][graph->num_vertices - 1]) {
                colors[graph->num_vertices - 1] = MIN_COLOR;
                break;
            }
            if (j < graph->num_vertices - 1 && is_valid_color(i, graph->num_vertices - 1, colors)) {
                bool result = graph_coloring(graph, colors, num_colors);
                if (result) {
                    return true;
                }
                colors[graph->num_vertices - 1] = MIN_COLOR;
            }
        }
    }

    return false;
}

int main() {
    int num_vertices, num_edges, color;
    scanf("%d %d", &num_vertices, &num_edges);

    Graph graph;
    graph.num_vertices = num_vertices;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph.adj_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph.adj_matrix[u][v] = 1;
        graph.adj_matrix[v][u] = 1;
    }

    int num_colors = 3;
    int *colors = (int *)calloc(num_vertices, sizeof(int));

    bool result = graph_coloring(&graph, colors, num_colors);

    if (result) {
        printf("Graph Coloring:\n");
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d is colored with color %d\n", i, colors[i]);
        }
    } else {
        printf("Graph cannot be colored with given number of colors.\n");
    }

    free(colors);
    return 0;
}
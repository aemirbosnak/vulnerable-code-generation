//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} graph;

typedef struct color {
    int r;
    int g;
    int b;
} color;

graph *create_graph(int num_vertices, int num_edges) {
    graph *g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;
    g->adj_matrix = malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        g->adj_matrix[i] = malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
    return g;
}

void add_edge(graph *g, int v1, int v2) {
    g->adj_matrix[v1][v2] = 1;
    g->adj_matrix[v2][v1] = 1;
}

int is_safe(graph *g, int v, color *colors, int c) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adj_matrix[v][i] == 1 && colors[i].r == c) {
            return FALSE;
        }
    }
    return TRUE;
}

int graph_coloring(graph *g, color *colors, int v) {
    if (v == g->num_vertices) {
        return TRUE;
    }
    for (int c = 0; c < 3; c++) {
        if (is_safe(g, v, colors, c)) {
            colors[v].r = c;
            if (graph_coloring(g, colors, v + 1) == TRUE) {
                return TRUE;
            }
            colors[v].r = -1;
        }
    }
    return FALSE;
}

int main() {
    int n, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    graph *g = create_graph(n, e);
    printf("Enter the edges: ");
    for (int i = 0; i < e; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        add_edge(g, v1, v2);
    }
    color *colors = malloc(n * sizeof(color));
    for (int i = 0; i < n; i++) {
        colors[i].r = -1;
    }
    if (graph_coloring(g, colors, 0) == TRUE) {
        printf("Graph can be colored with 3 colors:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d: (%d, %d, %d)\n", i, colors[i].r, colors[i].g, colors[i].b);
        }
    } else {
        printf("Graph cannot be colored with 3 colors\n");
    }
    return 0;
}
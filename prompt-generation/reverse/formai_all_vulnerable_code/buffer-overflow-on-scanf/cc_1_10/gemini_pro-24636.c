//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int num_vertices;
    int num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} graph;

typedef struct {
    int num_colors;
    int colors[MAX_VERTICES];
} coloring;

graph *create_graph(int num_vertices, int num_edges) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }

    return g;
}

void add_edge(graph *g, int u, int v) {
    g->adj_matrix[u][v] = 1;
    g->adj_matrix[v][u] = 1;
}

coloring *create_coloring(int num_colors) {
    coloring *c = (coloring *)malloc(sizeof(coloring));
    c->num_colors = num_colors;

    for (int i = 0; i < MAX_VERTICES; i++) {
        c->colors[i] = -1;
    }

    return c;
}

int is_valid_coloring(graph *g, coloring *c) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = i + 1; j < g->num_vertices; j++) {
            if (g->adj_matrix[i][j] == 1 && c->colors[i] == c->colors[j]) {
                return 0;
            }
        }
    }

    return 1;
}

int graph_coloring(graph *g, coloring *c) {
    if (c->num_colors < 1) {
        return 0;
    }

    if (is_valid_coloring(g, c)) {
        return 1;
    }

    for (int i = 0; i < g->num_vertices; i++) {
        if (c->colors[i] == -1) {
            for (int j = 0; j < c->num_colors; j++) {
                c->colors[i] = j;
                if (graph_coloring(g, c)) {
                    return 1;
                }
                c->colors[i] = -1;
            }
        }
    }

    return 0;
}

int main() {
    int num_vertices, num_edges;
    scanf("%d %d", &num_vertices, &num_edges);

    graph *g = create_graph(num_vertices, num_edges);

    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(g, u, v);
    }

    int num_colors;
    scanf("%d", &num_colors);

    coloring *c = create_coloring(num_colors);

    int result = graph_coloring(g, c);

    if (result) {
        printf("Graph can be colored with %d colors\n", num_colors);
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, c->colors[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors\n", num_colors);
    }

    return 0;
}
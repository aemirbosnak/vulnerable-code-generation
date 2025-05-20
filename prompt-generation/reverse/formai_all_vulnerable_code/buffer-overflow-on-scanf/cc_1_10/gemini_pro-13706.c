//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} graph;

typedef struct color {
    int value;
    char *name;
} color;

color colors[MAX_COLORS] = {
    {0, "Red"},
    {1, "Green"},
    {2, "Blue"},
    {3, "Yellow"},
    {4, "Orange"},
    {5, "Purple"},
    {6, "Brown"},
    {7, "Black"},
    {8, "White"},
    {9, "Gray"}
};

graph *create_graph(int num_vertices, int num_edges) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;
    g->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        g->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
    return g;
}

void destroy_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->adj_matrix[i]);
    }
    free(g->adj_matrix);
    free(g);
}

void add_edge(graph *g, int u, int v) {
    g->adj_matrix[u][v] = 1;
    g->adj_matrix[v][u] = 1;
}

int is_safe(graph *g, int v, int color, int *colors) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adj_matrix[v][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graph_color(graph *g, int *colors, int v) {
    if (v == g->num_vertices) {
        return 1;
    }

    for (int i = 0; i < MAX_COLORS; i++) {
        if (is_safe(g, v, i, colors)) {
            colors[v] = i;
            if (graph_color(g, colors, v + 1)) {
                return 1;
            }
            colors[v] = -1;
        }
    }

    return 0;
}

void print_solution(graph *g, int *colors) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d\t%s\n", i, colors[i] >= 0 ? colors[i] : "None");
    }
}

int main() {
    int num_vertices, num_edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    graph *g = create_graph(num_vertices, num_edges);

    int u, v;
    for (int i = 0; i < num_edges; i++) {
        printf("Enter the vertices connected by edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        add_edge(g, u, v);
    }

    int *colors = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = -1;
    }

    if (graph_color(g, colors, 0)) {
        printf("Graph colored successfully!\n");
        print_solution(g, colors);
    } else {
        printf("Graph cannot be colored with %d colors.\n", MAX_COLORS);
    }

    destroy_graph(g);
    free(colors);

    return 0;
}
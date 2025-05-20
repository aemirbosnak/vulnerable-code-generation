//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_DEGREE 50

// Define the graph struct
typedef struct {
    int num_vertices;
    int num_colors;
    int colors[MAX_VERTICES];
    int degree[MAX_VERTICES];
    int adjacency[MAX_VERTICES][MAX_DEGREE];
} Graph;

// Function that initializes the graph
void initialize_graph(Graph *g) {
    g->num_vertices = 0;
    g->num_colors = 0;
    memset(g->degree, 0, sizeof(g->degree));
    memset(g->colors, 0, sizeof(g->colors));
}

// Function that adds an edge to the graph
void add_edge(Graph *g, int u, int v) {
    // Add v to u's adjacency list
    g->adjacency[u][g->degree[u]++] = v;
    // Add u to v's adjacency list
    g->adjacency[v][g->degree[v]++] = u;
}

// Function that checks if a vertex can be colored with a given color
bool is_valid_color(Graph *g, int v, int color) {
    for (int i = 0; i < g->degree[v]; i++) {
        int adj_v = g->adjacency[v][i];
        if (g->colors[adj_v] == color) {
            return false;
        }
    }
    return true;
}

// Function for recursive backtracking
bool color_graph_r(Graph *g, int v) {
    if (v == g->num_vertices) {
        return true;
    }
    for (int i = 1; i <= g->num_colors; i++) {
        if (is_valid_color(g, v, i)) {
            g->colors[v] = i;
            if (color_graph_r(g, v + 1)) {
                return true;
            }
            g->colors[v] = 0;
        }
    }
    return false;
}

// Function that solves the graph coloring problem
bool color_graph(Graph *g) {
    return color_graph_r(g, 0);
}

int main() {
    // Initialize the graph
    Graph g;
    initialize_graph(&g);

    // Read the number of vertices and edges
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    // Read the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        add_edge(&g, u - 1, v - 1);
    }

    // Read the number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &g.num_colors);

    // Solve the graph coloring problem
    if (color_graph(&g)) {
        // Print the coloring
        printf("Coloring:\n");
        for (int i = 0; i < g.num_vertices; i++) {
            printf("%d ", g.colors[i]);
        }
        printf("\n");
    } else {
        printf("Graph cannot be colored with %d colors.\n", g.num_colors);
    }

    return 0;
}
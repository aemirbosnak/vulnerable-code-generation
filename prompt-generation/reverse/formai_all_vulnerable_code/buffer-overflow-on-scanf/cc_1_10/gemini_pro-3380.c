//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int vertices, colors, edges;
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int vertex_colors[MAX_VERTICES];

void read_graph(void) {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &colors);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    for (i = 0; i < edges; i++) {
        int u, v;

        printf("Enter the edge (u, v): ");
        scanf("%d %d", &u, &v);

        adjacency_matrix[u][v] = 1;
        adjacency_matrix[v][u] = 1;
    }
}

int is_safe(int vertex, int color) {
    int i;

    for (i = 0; i < vertices; i++) {
        if (adjacency_matrix[vertex][i] && vertex_colors[i] == color) {
            return 0;
        }
    }

    return 1;
}

int graph_coloring(int vertex) {
    if (vertex == vertices) {
        return 1;
    }

    for (int i = 0; i < colors; i++) {
        if (is_safe(vertex, i)) {
            vertex_colors[vertex] = i;

            if (graph_coloring(vertex + 1)) {
                return 1;
            }

            vertex_colors[vertex] = -1;
        }
    }

    return 0;
}

int main(void) {
    read_graph();

    if (graph_coloring(0)) {
        printf("Graph can be colored with %d colors.\n", colors);

        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d colored with color %d.\n", i, vertex_colors[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", colors);
    }

    return 0;
}
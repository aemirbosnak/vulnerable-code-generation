//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;
int num_colors;

int is_safe(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int vertex) {
    if (vertex == num_vertices) {
        return 1;
    }

    for (int color = 1; color <= num_colors; color++) {
        if (is_safe(vertex, color)) {
            colors[vertex] = color;
            if (graph_coloring(vertex + 1)) {
                return 1;
            }
            colors[vertex] = 0;
        }
    }

    return 0;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (graph_coloring(0)) {
        printf("Graph can be colored with %d colors.\n", num_colors);
        printf("Colors assigned to the vertices:\n");
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: %d\n", i, colors[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", num_colors);
    }

    return 0;
}
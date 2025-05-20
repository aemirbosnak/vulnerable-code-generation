//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES] = {[0 ... MAX_VERTICES-1] = -1};
int num_vertices;
int num_colors;

int is_safe(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && colors[i] == color)
            return 0; // conflict found
    }
    return 1; // safe to use color
}

void assign_colors(int vertex) {
    if (vertex == num_vertices) {
        printf("Solution found!\n");
        for (int i = 0; i < num_vertices; i++)
            printf("Vertex %d => Color %d\n", i, colors[i]);
    }
    else {
        for (int i = 0; i < num_colors; i++) {
            if (is_safe(vertex, i)) {
                colors[vertex] = i;
                assign_colors(vertex + 1);
                colors[vertex] = -1; // backtrack
            }
        }
    }
}

int main() {
    // Input graph and number of colors
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter adjacency matrix (undirected graph):\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++)
            scanf("%d", &graph[i][j]);
    }
    printf("Enter number of colors: ");
    scanf("%d", &num_colors);

    // Solve using backtracking
    assign_colors(0);

    return 0;
}
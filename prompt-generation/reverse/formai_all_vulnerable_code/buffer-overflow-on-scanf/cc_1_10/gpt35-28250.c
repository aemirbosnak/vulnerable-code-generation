//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 50

int num_vertices, num_edges;
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int available_colors[MAX_COLORS];

void initialize_colors() {
    int i;
    for (i = 0; i < MAX_COLORS; i++) {
        available_colors[i] = i + 1;
    }
}

void read_graph() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }
}

bool is_safe(int vertex, int c) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (adjacency_matrix[vertex][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

void graph_color(int vertex) {
    int c, i;
    for (i = 0; i < MAX_COLORS; i++) {
        c = available_colors[i];
        if (is_safe(vertex, c)) {
            color[vertex] = c;
            if (vertex == num_vertices - 1) {
                return;
            }
            graph_color(vertex + 1);
            color[vertex] = 0;
        }
    }
}

void print_solution() {
    int i;
    printf("\nThe assigned colors are:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }
}

int main() {
    read_graph();
    initialize_colors();
    graph_color(0);
    print_solution();
    return 0;
}
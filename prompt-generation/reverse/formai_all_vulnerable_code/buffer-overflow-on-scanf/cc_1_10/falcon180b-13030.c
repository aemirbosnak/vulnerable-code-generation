//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 10

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int n_vertices;
int n_colors;

void read_graph(void) {
    printf("Enter the number of vertices: ");
    scanf("%d", &n_vertices);

    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
}

void color_graph(int v, int color, int *visited) {
    visited[v] = 1;
    for (int i = 0; i < n_vertices; i++) {
        if (adj_matrix[v][i] == 1 &&!visited[i]) {
            if (color == n_colors - 1) {
                printf("Graph cannot be colored with %d colors.\n", n_colors);
                exit(1);
            }
            color_graph(i, color + 1, visited);
        }
    }
}

int main(void) {
    printf("Enter the number of colors: ");
    scanf("%d", &n_colors);

    read_graph();

    int visited[MAX_VERTICES];
    for (int i = 0; i < n_vertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n_vertices; i++) {
        if (!visited[i]) {
            color_graph(i, 0, visited);
        }
    }

    printf("Graph can be colored with %d colors.\n", n_colors);

    return 0;
}
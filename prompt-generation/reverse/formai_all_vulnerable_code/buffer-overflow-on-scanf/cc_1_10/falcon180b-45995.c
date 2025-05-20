//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int num_vertices;
int **adjacency_matrix;
int *vertex_colors;

void initialize_graph(int vertices) {
    num_vertices = vertices;
    adjacency_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        adjacency_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            adjacency_matrix[i][j] = rand() % 2;
        }
    }
    vertex_colors = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        vertex_colors[i] = rand() % MAX_COLORS;
    }
}

void print_graph() {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void print_colors() {
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", vertex_colors[i]);
    }
    printf("\n");
}

int is_valid_color(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (adjacency_matrix[vertex][i] == 1 && vertex_colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    for (int i = 0; i < num_vertices; i++) {
        vertex_colors[i] = rand() % MAX_COLORS;
        while (!is_valid_color(i, vertex_colors[i])) {
            vertex_colors[i] = rand() % MAX_COLORS;
        }
    }
}

int main() {
    srand(time(NULL));
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initialize_graph(vertices);
    printf("Initial graph:\n");
    print_graph();
    color_graph();
    printf("Colored graph:\n");
    print_graph();
    print_colors();
    return 0;
}
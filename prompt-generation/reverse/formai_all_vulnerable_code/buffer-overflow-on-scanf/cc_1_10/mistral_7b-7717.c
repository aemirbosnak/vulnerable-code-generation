//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MIN_COLOR 0

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int num_vertices, num_edges, min_colors;
int color_assigned[MAX_VERTICES];

void print_matrix() {
    int i, j;
    printf("Adjacency matrix:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int find_min_uncolored_vertex() {
    int min_index = 0, min_value = MAX_VERTICES;
    for (int i = 0; i < num_vertices; i++) {
        if (color_assigned[i] == MIN_COLOR && adj_matrix[i][min_value] != 0) {
            min_value = i;
        }
        if (color_assigned[i] == MIN_COLOR) {
            if (min_value > i && adj_matrix[i][min_value] == 0) {
                min_value = i;
            }
        }
    }
    return min_value;
}

void graph_coloring() {
    int current_vertex = 0;
    min_colors = num_vertices;

    while (min_colors > num_vertices) {
        int next_color = MIN_COLOR;
        current_vertex = find_min_uncolored_vertex();
        color_assigned[current_vertex] = next_color;

        for (int neighbor = 0; neighbor < num_vertices; neighbor++) {
            if (adj_matrix[neighbor][current_vertex] != 0 && color_assigned[neighbor] == next_color) {
                min_colors = num_vertices;
                break;
            }
            if (color_assigned[neighbor] == MIN_COLOR) {
                next_color++;
            }
        }
        if (min_colors == num_vertices) {
            min_colors--;
        }
    }
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &num_vertices, &num_edges);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    graph_coloring();
    printf("Minimum number of colors needed: %d\n", min_colors + 1);

    return 0;
}
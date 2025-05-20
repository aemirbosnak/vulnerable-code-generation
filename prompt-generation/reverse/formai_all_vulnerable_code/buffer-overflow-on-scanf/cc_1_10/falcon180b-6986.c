//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int vertices;
int colors[MAX_COLORS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void initialize_adj_matrix(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                adj_matrix[i][j] = 0;
            } else {
                adj_matrix[i][j] = rand() % 2;
            }
        }
    }
}

int get_neighbor_count(int vertex) {
    int count = 0;
    for (int i = 0; i < vertices; i++) {
        if (adj_matrix[vertex][i] == 1) {
            count++;
        }
    }
    return count;
}

int color_graph(int vertices, int colors[], int start_vertex) {
    int color_count = 0;
    int vertex_colors[vertices];
    for (int i = 0; i < vertices; i++) {
        vertex_colors[i] = 0;
    }
    vertex_colors[start_vertex] = 1;
    int next_vertex = start_vertex;
    while (color_count < vertices) {
        int neighbor_count = get_neighbor_count(next_vertex);
        int found_color = 0;
        for (int k = 0; k < vertices; k++) {
            if (vertex_colors[k] == 1 && neighbor_count == 0) {
                vertex_colors[next_vertex] = colors[k];
                found_color = 1;
                break;
            }
        }
        if (found_color == 0) {
            vertex_colors[next_vertex] = colors[color_count];
            color_count++;
        }
        next_vertex++;
        if (next_vertex == vertices) {
            next_vertex = 0;
        }
    }
    return color_count;
}

int main() {
    srand(time(NULL));
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initialize_adj_matrix(vertices);
    int color_count = color_graph(vertices, colors, 0);
    printf("The graph was colored using %d colors.\n", color_count);
    return 0;
}
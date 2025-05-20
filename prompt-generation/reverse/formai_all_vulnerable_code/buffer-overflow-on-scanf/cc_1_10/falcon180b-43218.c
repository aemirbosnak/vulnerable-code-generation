//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

int num_vertices, num_edges;
int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int color_array[MAX_VERTICES];

void create_graph(int vertices, int edges) {
    int u, v;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        adj_matrix[u][v] = adj_matrix[v][u] = 1;
    }
}

int is_safe(int vertex, int color, int v) {
    if (vertex == v)
        return 1;
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[vertex][i] && color_array[i] == color)
            return 0;
    }
    return 1;
}

void color_graph(int start_vertex, int color) {
    int v = start_vertex;
    color_array[v] = color;
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[v][i] &&!color_array[i]) {
            int new_color = color + 1;
            while (!is_safe(v, new_color, i)) {
                new_color++;
            }
            color_graph(i, new_color);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    create_graph(num_vertices, num_edges);
    int max_colors = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (!color_array[i]) {
            color_graph(i, 1);
            max_colors = max_colors > num_vertices? max_colors : num_vertices;
        }
    }
    printf("Minimum number of colors required: %d\n", max_colors);
    return 0;
}
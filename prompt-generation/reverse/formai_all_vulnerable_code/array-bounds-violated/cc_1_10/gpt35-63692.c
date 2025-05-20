//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

int is_safe(int vertex_index, int color_index, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[vertex_index][i] && colors[i] == color_index) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int vertex_index, int num_vertices, int num_colors) {
    if (vertex_index == num_vertices) {
        return 1;
    }
    
    for (int i = 1; i <= num_colors; i++) {
        if (is_safe(vertex_index, i, num_vertices)) {
            colors[vertex_index] = i;
            if (graph_coloring(vertex_index + 1, num_vertices, num_colors)) {
                return 1;
            }
            colors[vertex_index] = 0;
        }
    }
    return 0;
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    
    int num_edges;
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    
    for (int i = 0; i < num_edges; i++) {
        int vertex_1, vertex_2;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &vertex_1, &vertex_2);
        adj_matrix[vertex_1][vertex_2] = 1;
        adj_matrix[vertex_2][vertex_1] = 1;
    }
    
    int num_colors;
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);
    
    if (graph_coloring(0, num_vertices, num_colors)) {
        printf("The coloring scheme is as follows:\n");
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("No coloring is possible with %d colors.\n", num_colors);
    }
    
    return 0;
}
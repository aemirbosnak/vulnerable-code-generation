//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of vertices and colors
#define MAX_VERTICES 100
#define MAX_COLORS 4

// Initialize the adjacency matrix and vertex colors
int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int vertex_color[MAX_VERTICES];

// Function to check if a color can be assigned to a vertex
bool is_possible_color(int vertex_index, int color_index, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[vertex_index][i] && vertex_color[i] == color_index) {
            return false;
        }
    }
    return true;
}

// Function to assign colors to vertices recursively
bool assign_colors(int num_vertices, int num_colors, int vertex_index) {
    // Base case: all vertices have been colored
    if (vertex_index == num_vertices) {
        return true;
    }
    // Try all possible colors for the current vertex
    for (int color_index = 1; color_index <= num_colors; color_index++) {
        if (is_possible_color(vertex_index, color_index, num_vertices)) {
            vertex_color[vertex_index] = color_index;
            // Recursively color the remaining vertices
            if (assign_colors(num_vertices, num_colors, vertex_index + 1)) {
                return true;
            }
            vertex_color[vertex_index] = 0; // Backtrack
        }
    }
    // If no color can be assigned, return false
    return false;
}

int main() {
    int num_vertices, num_edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    // Initialize the adjacency matrix
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    // Get the edges from the user and update the adjacency matrix
    printf("Enter the edges (vertex_1 vertex_2):\n");
    for (int i = 0; i < num_edges; i++) {
        int vertex_1, vertex_2;
        scanf("%d %d", &vertex_1, &vertex_2);
        adj_matrix[vertex_1][vertex_2] = 1;
        adj_matrix[vertex_2][vertex_1] = 1;
    }
    // Color the vertices using backtracking
    if (assign_colors(num_vertices, MAX_COLORS, 0)) {
        printf("The vertices can be colored with %d colors as follows:\n", MAX_COLORS);
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, vertex_color[i]);
        }
    }
    else {
        printf("The vertices cannot be colored with %d colors.\n", MAX_COLORS);
    }
    return 0;
}
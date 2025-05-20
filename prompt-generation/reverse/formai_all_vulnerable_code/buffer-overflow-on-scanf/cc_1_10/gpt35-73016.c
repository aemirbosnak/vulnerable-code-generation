//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to store graph
int colors[MAX_VERTICES]; // Array to store colors of vertices
int num_vertices; // Number of vertices in graph

bool isSafe(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[vertex][i] && color == colors[i]) // If vertex has adjacent vertices with same color, it is not safe to color with that color
            return false;
    }
    return true;
}

bool graphColoringUtil(int vertex, int num_colors) {
    if (vertex == num_vertices) // If all vertices are colored, return true
        return true;

    for (int i = 1; i <= num_colors; i++) {
        if (isSafe(vertex, i)) {
            colors[vertex] = i; // Assign color to vertex
            if (graphColoringUtil(vertex+1, num_colors)) // Recursively call function for next vertex
                return true;
            colors[vertex] = 0; // If unable to color next vertex, backtrack and try next color for current vertex
        }
    }
    return false; // If all colors are tried for current vertex and none is safe, return false
}

bool graphColoring(int num_colors) {
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = 0; // Initialize array with all zeros
        
        if (!graphColoringUtil(i, num_colors)) // Call recursive function for each vertex
            return false;
    }
    return true; // If graph is successfully colored, return true
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    int num_colors;
    printf("Enter number of colors: ");
    scanf("%d", &num_colors);

    if (graphColoring(num_colors)) { // Call graphColoring function with number of colors
        printf("Graph can be colored using %d colors:\n", num_colors);
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    }
    else {
        printf("Graph cannot be colored using %d colors.\n", num_colors);
    }

    return 0;
}
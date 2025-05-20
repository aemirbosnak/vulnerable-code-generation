//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 100

// Number of colors
#define MAX_COLORS 10

// Adjacency matrix representation of the graph
int graph[MAX_VERTICES][MAX_VERTICES];

// Array to store the color of each vertex
int colors[MAX_VERTICES];

// Function to check if a color can be assigned to a vertex
bool isSafe(int vertex, int color, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

// Function to assign colors to vertices recursively
bool assignColors(int num_vertices, int num_colors, int vertex) {
    if (vertex == num_vertices) {
        return true; // All vertices have been colored
    }
    for (int i = 1; i <= num_colors; i++) { // Try all possible colors
        if (isSafe(vertex, i, num_vertices)) {
            colors[vertex] = i; // Assign color to vertex
            if (assignColors(num_vertices, num_colors, vertex + 1)) {
                return true; // Success, all vertices have been colored
            }
            colors[vertex] = 0; // Backtrack, reset color of vertex
        }
    }
    return false; // No valid coloring found
}

int main() {
    // Initialize the graph and colors
    int num_vertices, num_edges;
    printf("Enter the number of vertices and edges (separated by a space): ");
    scanf("%d %d", &num_vertices, &num_edges);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
        colors[i] = 0;
    }

    // Input the edges of the graph
    printf("Enter the edges (vertex1 vertex2):\n");
    int vertex1, vertex2;
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    // Find the minimum number of colors needed to color the graph
    int num_colors = 1;
    while (!assignColors(num_vertices, num_colors, 0)) {
        num_colors++;
    }

    // Print the colors assigned to each vertex
    printf("Colors assigned to vertices:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }

    return 0;
}
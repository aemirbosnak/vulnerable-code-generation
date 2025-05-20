//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices a graph can have
#define MAX_COLOR 10 // Maximum number of colors that can be assigned to a graph

int num_vertices; // Number of vertices in the graph
int num_edges; // Number of edges in the graph
int color[MAX_VERTICES]; // Array to store colors assigned to each vertex
int adj_matrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to represent the graph

// Function to read input from user
void read_input() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
}

// Function to check if a color is valid for a vertex
bool is_valid_color(int vertex, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Function to color the graph recursively
bool color_graph(int vertex) {
    if (vertex == num_vertices) {
        return true; // All vertices have been colored successfully
    }
    for (int c = 1; c <= MAX_COLOR; c++) { // Try all colors for the current vertex
        if (is_valid_color(vertex, c)) {
            color[vertex] = c; // Assign the color
            if (color_graph(vertex + 1)) {
                return true; // If the rest of the graph can be colored successfully, return true
            }
            color[vertex] = 0; // Backtrack to the previous vertex and try a different color
        }
    }
    return false; // No valid color found, backtrack further
}

// Function to print the colors assigned to each vertex
void print_colors() {
    printf("The colors assigned to each vertex are:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

int main() {
    read_input();
    if (color_graph(0)) {
        print_colors();
    } else {
        printf("The graph cannot be colored.\n");
    }
    return 0;
}
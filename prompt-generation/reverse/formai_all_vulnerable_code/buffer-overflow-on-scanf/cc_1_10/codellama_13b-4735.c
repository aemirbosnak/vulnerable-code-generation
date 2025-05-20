//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
/*
 * Retro Style Graph Coloring Problem
 *
 * Description: Given a graph G = (V, E), find a proper coloring of the graph such that no two adjacent vertices have the same color.
 *
 * Input: A graph G = (V, E) represented as an adjacency matrix A, where A[i, j] = 1 if there is an edge between vertices i and j, and A[i, j] = 0 otherwise.
 *
 * Output: A proper coloring of the graph G, represented as an array of integers C, where C[i] is the color of vertex i.
 *
 * Time complexity: O(V^2)
 * Space complexity: O(V)
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Adjacency matrix
int A[MAX_VERTICES][MAX_VERTICES];

// Color array
int C[MAX_VERTICES];

// Number of vertices and edges
int V, E;

// Helper function to check if a color is valid for a given vertex
int is_valid_color(int vertex, int color) {
    for (int i = 0; i < V; i++) {
        if (A[vertex][i] == 1 && C[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to assign colors to vertices
void color_graph(int vertex) {
    // Base case: all vertices have been colored
    if (vertex == V) {
        return;
    }

    // Try all possible colors for the current vertex
    for (int color = 0; color < V; color++) {
        if (is_valid_color(vertex, color)) {
            C[vertex] = color;
            color_graph(vertex + 1);
        }
    }
}

int main() {
    // Read graph from input
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Assign colors to vertices
    color_graph(0);

    // Print coloring
    for (int i = 0; i < V; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}
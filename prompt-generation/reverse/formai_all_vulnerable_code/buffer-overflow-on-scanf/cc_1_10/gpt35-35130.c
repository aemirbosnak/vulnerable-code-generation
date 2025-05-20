//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 1000

int n, m; // Number of vertices and edges
int graph[MAX_VERTICES][MAX_VERTICES]; // Graph adjacency matrix
int color[MAX_VERTICES]; // Color array

// Check if it is safe to assign color to vertex v
bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve Graph Coloring Problem
bool graphColoringUtil(int v) {
    // Base case: If all vertices are assigned a color, return true
    if (v == n) {
        return true;
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if it is safe to assign color c to vertex v
        if (isSafe(v, c)) {
            // Assign color c to vertex v
            color[v] = c;

            // Recursively assign colors to remaining vertices
            if (graphColoringUtil(v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution then remove it
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return false;
}

// Driver function to solve Graph Coloring Problem
void graphColoring() {
    if (graphColoringUtil(0)) {
        printf("Solution exists!\n");
        printf("Vertex\tColor\n");
        for (int i = 0; i < n; i++) {
            printf("%d\t%d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist!\n");
    }
}

// Main function
int main() {
    // Get input
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of colors: ");
    scanf("%d", &m);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Solve Graph Coloring Problem
    graphColoring();

    return 0;
}
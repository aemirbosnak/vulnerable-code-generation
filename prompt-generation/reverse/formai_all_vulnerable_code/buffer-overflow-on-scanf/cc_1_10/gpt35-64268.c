//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices in the graph
#define MAX_COLORS 10 // Maximum number of colors for vertex coloring

int graph[MAX_VERTICES][MAX_VERTICES]; // The graph representation
int colors[MAX_VERTICES]; // The colors for the vertices

bool isSafe(int v, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false; // A connected vertex has the same color
        }
    }
    return true; // No connected vertex has the same color
}

bool graphColoring(int n, int colorsCount, int v) {
    if (v == n) {
        return true; // All vertices have been colored
    }
    
    for (int c = 1; c <= colorsCount; c++) {
        if (isSafe(v, c, n)) {
            colors[v] = c; // Color the vertex with the available color
            if (graphColoring(n, colorsCount, v+1)) {
                return true; // Continue with the next vertex
            }
            colors[v] = 0; // Backtrack and reset color to 0
        }
    }
    
    return false; // All colors have been tried and failed
}

void printColors(int n) {
    printf("Vertex colors:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

int main() {
    int n, m; // Number of vertices and edges
    int u, v; // Vertices for an edge

    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("\nEnter the maximum number of colors for vertex coloring (max %d): ", MAX_COLORS);
    scanf("%d", &m);
    
    if (graphColoring(n, m, 0)) {
        printColors(n);
    } else {
        printf("Vertex coloring is not possible with the given parameters.");
    }

    return 0;
}
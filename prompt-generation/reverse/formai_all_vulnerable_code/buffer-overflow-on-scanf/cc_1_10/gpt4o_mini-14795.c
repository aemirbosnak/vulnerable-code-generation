//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_COLORS 5

// Function to check if it is safe to color vertex v with color c
int isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int colors[MAX_VERTICES], int v, int c, int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0; // Not safe
        }
    }
    return 1; // Safe to color
}

// Recursive function to solve the graph coloring problem
int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int colors[MAX_VERTICES], int v, int m, int vertices) {
    // Base case: If all vertices are assigned a color, return true
    if (v == vertices) {
        return 1; // Success
    }
    
    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, colors, v, c, vertices)) {
            colors[v] = c; // Assign color c to vertex v
            if (graphColoringUtil(graph, colors, v + 1, m, vertices)) {
                return 1; // If successful, propagate success
            }
            colors[v] = 0; // Backtrack
        }
    }
    return 0; // Failure, no solution found
}

// Graph coloring function
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int vertices) {
    int colors[MAX_VERTICES] = {0}; // Initialize color assignments

    if (graphColoringUtil(graph, colors, 0, m, vertices) == 0) {
        printf("No solution exists.\n");
    } else {
        printf("Solution exists: Assigned colors are:\n");
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d --> Color %d\n", i, colors[i]);
        }
    }
}

// Helper function to get user input for the graph
void inputGraph(int graph[MAX_VERTICES][MAX_VERTICES], int *vertices) {
    int edges;
    printf("Enter the number of vertices: ");
    scanf("%d", vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }
}

// Main function
int main() {
    int vertices;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int m;

    inputGraph(graph, &vertices);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, vertices);

    return 0;
}
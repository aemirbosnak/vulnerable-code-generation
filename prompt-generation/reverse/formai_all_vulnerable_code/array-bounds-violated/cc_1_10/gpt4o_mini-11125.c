//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function to check if the current color assignment is safe for vertex 'v'
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

// Recursive function to solve the m-coloring problem
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    // Base case: If all vertices are assigned a color then return true
    if (v == V) {
        return true;
    }

    // Try different colors for vertex 'v'
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c, V)) {
            color[v] = c; // Assign color c to vertex v
            
            // Recursively assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }
            
            // If assigning color c doesn't lead to a solution then remove it
            color[v] = 0; // Backtrack
        }
    }

    return false; // No color can be assigned
}

// Function to solve the m-coloring problem
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES] = {0}; // 0 means no color is assigned

    // Call the recursive utility function
    if (!graphColoringUtil(graph, m, color, 0, V)) {
        printf("Solution does not exist\n");
        return false;
    }
    
    // Print the assigned colors
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
    }
    return true;
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; 
    int V, E, u, v, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    printf("Enter the edges (u v) where 1 <= u, v <= %d:\n", V);
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1; // Mark the edge as bidirectional
        graph[v - 1][u - 1] = 1; // Mark as bidirectional
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);
    return 0;
}
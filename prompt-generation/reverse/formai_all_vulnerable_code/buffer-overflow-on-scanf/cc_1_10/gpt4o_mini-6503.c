//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function Prototypes
void printSolution(int color[], int V);
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c);
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int m);
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V);

// Main Program
int main() {
    int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix representation
    int V, m;
    
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &V);
    
    if (V <= 0 || V > MAX_VERTICES) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("Enter the adjacency matrix (%d x %d) for the graph:\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors to use: ");
    scanf("%d", &m);

    if (graphColoring(graph, m, V)) {
        printf("Graph can be colored with %d colors.\n", m);
    } else {
        printf("Graph cannot be colored with %d colors.\n", m);
    }
    
    return 0;
}

// Function to print solution
void printSolution(int color[], int V) {
    printf("Assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

// Check if the current color assignment is safe for vertex v
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Recursive utility function to solve graph coloring problem
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int m) {
    if (v == MAX_VERTICES) {
        printSolution(color, MAX_VERTICES);
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, color, v + 1, m)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

// Driver function to check if the graph can be colored with m colors
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES] = {0}; // Initialize all vertices as unassigned

    if (!graphColoringUtil(graph, color, 0, m)) {
        printf("Solution does not exist\n");
        return false;
    }

    return true;
}
//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function prototypes
void printSolution(int color[], int numVertices);
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int vertex, int c, int numVertices);
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int vertex, int numVertices);
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int numVertices);

// Main function
int main() {
    int graph[MAX_VERTICES][MAX_VERTICES], numVertices, m;
    
    printf("Welcome to the Exciting Graph Coloring Problem Solver!\n");
    
    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix (0 or 1) for the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors you want to use: ");
    scanf("%d", &m);

    printf("Looking for a solution using %d colors...\n", m);
    
    if (graphColoring(graph, m, numVertices)) {
        printf("Yay! A solution exists!\n");
    } else {
        printf("Oops! No solution found with %d colors.\n", m);
    }
    
    return 0;
}

// Function to print the colored solution
void printSolution(int color[], int numVertices) {
    printf("Vertex Colors:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
}

// Check if the current color can be assigned to a vertex
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int vertex, int c, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Utility function to solve the graph coloring problem
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int vertex, int numVertices) {
    if (vertex == numVertices) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, vertex, c, numVertices)) {
            color[vertex] = c;
            if (graphColoringUtil(graph, m, color, vertex + 1, numVertices)) {
                return true;
            }
            color[vertex] = 0; // Backtrack
        }
    }
    
    return false;
}

// Main function to solve the graph coloring problem
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int numVertices) {
    int color[MAX_VERTICES] = {0};
    if (graphColoringUtil(graph, m, color, 0, numVertices) == false) {
        return false;
    }
    printSolution(color, numVertices);
    return true;
}
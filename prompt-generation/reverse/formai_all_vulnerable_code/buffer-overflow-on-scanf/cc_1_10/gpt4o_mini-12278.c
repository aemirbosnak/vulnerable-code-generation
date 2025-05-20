//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Function to print the coloring of the graph
void printSolution(int color[], int V) {
    printf("Solution Exists: Following are the colors assigned to vertices:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);
}

// A utility function to check if the current color assignment is safe for vertex v
bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

// A recursive utility function to solve the graph coloring problem
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    // Base case: If all vertices are assigned a color then return true
    if (v == V)
        return true;

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c; // Assign color c to vertex v
            // Recur to assign colors to the remaining vertices
            if (graphColoringUtil(graph, m, color, v + 1, V))
                return true;
            // If assigning color c doesn't lead to a solution then remove it
            color[v] = 0;
        }
    }
    return false; // If no color can be assigned to this vertex
}

// Function to solve the m-coloring problem
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int V, int m) {
    int color[MAX_VERTICES] = {0}; // Initialize all vertices as uncolored

    // Call the recursive backtracking function
    if (graphColoringUtil(graph, m, color, 0, V) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(color, V);
    return true;
}

// Main function
int main() {
    int V, m;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &V);
    if (V > MAX_VERTICES || V < 1) {
        printf("Invalid number of vertices. Please use a number between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }

    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Solve the graph coloring problem
    graphColoring(graph, V, m);

    return 0;
}
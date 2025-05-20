//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Function to print the colors of the vertices
void printSolution(int color[], int V) {
    printf("Solution Exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
}

// Function to check if the current color assignment is safe for vertex v
int isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;  // Not safe if adjacent vertex has the same color
        }
    }
    return 1;  // Safe to assign color
}

// Backtracking function to solve the m-coloring problem
int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    if (v == V) {
        return 1;  // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c, V)) {
            color[v] = c;  // Assign color c to vertex v
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return 1;  // If successful, return true
            }
            color[v] = 0;  // If not successful, backtrack
        }
    }
    return 0;  // No solution found for this configuration
}

// Function to initiate graph coloring
int graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES] = {0};  // Color assignment for vertices
    if (graphColoringUtil(graph, m, color, 0, V) == 0) {
        printf("Solution does not exist.\n");
        return 0;
    }
    printSolution(color, V);
    return 1;
}

// Function to get the number of vertices and colors from the user
void inputGraph(int graph[MAX_VERTICES][MAX_VERTICES], int *V, int *m) {
    printf("Enter the number of vertices: ");
    scanf("%d", V);
    printf("Enter the number of colors: ");
    scanf("%d", m);
    
    printf("Enter the adjacency matrix (%d x %d):\n", *V, *V);
    for (int i = 0; i < *V; i++) {
        for (int j = 0; j < *V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int V, m;

    inputGraph(graph, &V, &m);
    graphColoring(graph, m, V);
    
    return 0;
}
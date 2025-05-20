//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 50

// Function to display the colored graph
void printSolution(int color[], int V) {
    printf("Solution: \n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
    }
    printf("\n");
}

// Function to check if the color can be assigned to vertex
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Backtracking function to find the solution
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    if (v == V) {
        return true; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c, V)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the remaining vertices
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

// Main function to solve the graph coloring problem
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES];
    memset(color, 0, sizeof(color)); // Initialize all vertices as uncolored

    if (graphColoringUtil(graph, m, color, 0, V)) {
        printSolution(color, V);
    } else {
        printf("No solution exists with %d colors\n", m);
    }
}

// Function to define and test a sample graph
int main() {
    printf("Welcome to the exciting Graph Coloring Problem!\n");
    
    int V; // Number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix

    printf("Enter the adjacency matrix (%dx%d, 0 for no edge and 1 for an edge):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int m; // Number of colors
    printf("Enter the number of colors available: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    return 0;
}
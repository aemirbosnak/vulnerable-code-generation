//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to print the color assignment
void printSolution(int color[], int V) {
    printf("Color Assignment:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i + 1, color[i]);
    }
}

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to assign colors to the vertices
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    // Base case: if all vertices are assigned a color
    if (v == V) {
        return true;
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if the assignment is safe
        if (isSafe(graph, color, v, c, V)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }

            // If assigning color c does not lead to a solution, remove it
            color[v] = 0;
        }
    }
    return false; // Backtrack
}

// Function to solve the graph coloring problem
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int V, int m) {
    int color[MAX_VERTICES] = {0}; // Color assignment for vertices

    if (graphColoringUtil(graph, m, color, 0, V) == false) {
        printf("Solution does not exist!\n");
        return;
    }

    printSolution(color, V); // Print the solution
}

int main() {
    printf("Welcome to the Graph Coloring Funhouse!\n");

    // Number of vertices
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Graph representation using an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    printf("Please enter the adjacency matrix (%dx%d) for the graph:\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Number of colors
    int m;
    printf("How many colors do you want to use? ");
    scanf("%d", &m);

    // Solve the graph coloring problem
    graphColoring(graph, V, m);

    printf("Thank you for playing with colors!\n");
    return 0;
}
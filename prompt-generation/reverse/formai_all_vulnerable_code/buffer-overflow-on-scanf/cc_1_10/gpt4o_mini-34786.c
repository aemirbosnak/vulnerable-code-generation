//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function to print the coloring of the graph
void printSolution(int color[], int V) {
    printf("Vertex Color Assignment:\n");
    for (int v = 0; v < V; v++) {
        printf("Vertex %d ---> Color %d\n", v, color[v]);
    }
}

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Recursive utility function to solve the coloring problem
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

// Function to solve the m-coloring problem
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES] = {0};

    if (graphColoringUtil(graph, m, color, 0, V) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(color, V);
    return true;
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int V, m;

    printf("Enter the number of vertices (up to %d): ", MAX_VERTICES);
    scanf("%d", &V);
    
    if (V < 1 || V > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting.\n");
        return 1;
    }

    printf("Enter the adjacency matrix for the graph (%d x %d entries):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (m <= 0) {
        printf("Invalid number of colors. Exiting.\n");
        return 1;
    }

    if (!graphColoring(graph, m, V)) {
        printf("No valid coloring found with %d colors.\n", m);
    }

    return 0;
}
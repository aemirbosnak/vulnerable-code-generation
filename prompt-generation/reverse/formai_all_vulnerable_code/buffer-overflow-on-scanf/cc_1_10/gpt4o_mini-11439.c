//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Function to display the current color arrangement
void printSolution(int color[], int V) {
    printf("Assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
}

// Check if the current color assignment is safe for vertex v
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Function to solve the graph coloring problem using backtracking
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c, V)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

// Function to solve the graph coloring problem
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES] = {0};

    if (!graphColoringUtil(graph, m, color, 0, V)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(color, V);
    return true;
}

int main() {
    int V;  // Number of vertices
    int m;  // Number of colors

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the adjacency matrix (0 or 1 only):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (!graphColoring(graph, m, V)) {
        // No solution was found
    }

    return 0;
}
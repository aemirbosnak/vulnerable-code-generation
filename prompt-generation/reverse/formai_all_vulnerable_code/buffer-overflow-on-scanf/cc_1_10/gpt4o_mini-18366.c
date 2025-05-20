//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// Function to check if the current color assignment is safe
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int vertex, int V) {
    // Base case: If all vertices are assigned a color return true
    if (vertex == V) {
        return true;
    }

    // Try different colors for vertex
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c, V)) {
            color[vertex] = c; // Assign color c to vertex

            // Recur to assign colors to the rest
            if (graphColoringUtil(graph, m, color, vertex + 1, V)) {
                return true;
            }

            // Backtrack - remove assigned color
            color[vertex] = 0;
        }
    }
    return false;
}

// Function to solve the graph coloring problem
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int V, int m) {
    int color[MAX_VERTICES] = {0}; // Color assignment

    // Start coloring from the first vertex
    if (graphColoringUtil(graph, m, color, 0, V)) {
        printf("Solution Exists: Following are the assigned colors:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("Solution does not exist\n");
    }
}

// Main function
int main() {
    int V; // Number of vertices
    int m; // Number of colors
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of colors: ");
    scanf("%d", &m);
    
    printf("Enter the edges (press -1 to stop):\n");
    int u, v;
    while (true) {
        printf("Edge (u, v): ");
        scanf("%d %d", &u, &v);
        if (u == -1 || v == -1) break;
        graph[u - 1][v - 1] = 1; // Note: assuming 1-based input
        graph[v - 1][u - 1] = 1; // Undirected graph
    }

    graphColoring(graph, V, m);

    return 0;
}
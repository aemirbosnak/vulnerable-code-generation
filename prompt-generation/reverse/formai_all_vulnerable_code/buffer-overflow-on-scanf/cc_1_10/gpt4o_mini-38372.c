//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 7 // Number of vertices in the graph

// Function to check if the current color assignment is valid for the vertex
bool isSafe(int graph[V][V], int vertex, int color[], int c) {
    for (int j = 0; j < V; j++) {
        if (graph[vertex][j] == 1 && color[j] == c) {
            return false;
        }
    }
    return true;
}

// Recursive utility function to solve the graph coloring problem
bool graphColorUtil(int graph[V][V], int m, int color[], int vertex) {
    if (vertex == V) {
        return true; // All vertices are processed
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c)) {
            color[vertex] = c; // Assign color c to vertex

            if (graphColorUtil(graph, m, color, vertex + 1)) {
                return true; // Continue to next vertex
            }
            color[vertex] = 0; // Backtrack
        }
    }
    return false; // No valid color assignment found
}

// Function to solve the m-coloring problem using recursion
bool graphColoring(int graph[V][V], int m) {
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }
    
    bool result = graphColorUtil(graph, m, color, 0);
    
    if (result) {
        printf("Coloring possible with %d colors:\n", m);
        for (int i = 0; i < V; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("Coloring not possible with %d colors.\n", m);
    }
    
    free(color);
    return result;
}

// Input graph function
void inputGraph(int graph[V][V]) {
    printf("Enter the adjacency matrix (%d x %d) for the graph:\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Main function
int main() {
    int graph[V][V] = {0};
    int m; // Number of colors

    inputGraph(graph);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);

    return 0;
}
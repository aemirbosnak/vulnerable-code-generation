//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Function declarations
void initializeGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);
void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int vertex, int c, int vertices);
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int vertex, int vertices);
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int vertices);

int main() {
    int vertices;
    int m;  // Number of colors
    int graph[MAX_VERTICES][MAX_VERTICES];

    // User input for number of vertices
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    // Ensure the input is within limits
    if (vertices < 1 || vertices > MAX_VERTICES) {
        printf("Error: The number of vertices must be between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }

    // User input for number of colors
    printf("Enter the number of colors to use: ");
    scanf("%d", &m);

    // Initialize the graph
    initializeGraph(graph, vertices);

    // Display the graph
    printf("The adjacency matrix of the graph is:\n");
    printGraph(graph, vertices);

    // Perform graph coloring
    graphColoring(graph, m, vertices);

    return 0;
}

// Graph initialization
void initializeGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;  // No edges initially
        }
    }

    int edges;
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: u v): \n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edges in both directions
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            graph[u][v] = 1;
            graph[v][u] = 1;  // Undirected graph
        } else {
            printf("Error: Invalid vertices %d and %d, skipping edge.\n", u, v);
        }
    }
}

// Print the adjacency matrix
void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Check if it's safe to color vertex with color c
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int vertex, int c, int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return false; // Adjacent vertex has same color
        }
    }
    return true;
}

// Utility function for graph coloring
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int vertex, int vertices) {
    if (vertex == vertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, vertex, c, vertices)) {
            color[vertex] = c; // Assign color c

            // Recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, color, vertex + 1, vertices)) {
                return true;
            }

            color[vertex] = 0; // Backtrack
        }
    }
    return false; // No solution exists
}

// Graph coloring function
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int vertices) {
    int color[MAX_VERTICES] = {0}; // Initialize all colors to 0

    if (graphColoringUtil(graph, m, color, 0, vertices)) {
        printf("Solution exists: Assigned colors are:\n");
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists for the given graph and number of colors.\n");
    }
}
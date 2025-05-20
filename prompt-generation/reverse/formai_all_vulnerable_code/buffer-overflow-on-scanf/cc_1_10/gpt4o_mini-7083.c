//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20  // Limit to a few vertices for snappy visualisation

// Function prototypes
void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int colors[], int v, int c, int vertices);
bool graphColorUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int colors[], int vertex, int vertices);
void solveGraphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int vertices);

int main() {
    int vertices, m;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Welcome to the Graph Coloring Problem Solver!\n");
    printf("------------------------------------------------\n");
    printf("Please enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Sorry! We support only up to %d vertices.\n", MAX_VERTICES);
        return 1;
    }

    printf("Now, let's define the adjacency matrix of your graph...\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("Edge between vertex %d and vertex %d (1 for YES, 0 for NO): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Great! Now, how many colors would you like to use? ");
    scanf("%d", &m);

    printf("Your adjacency matrix is:\n");
    displayGraph(graph, vertices);

    solveGraphColoring(graph, m, vertices);

    return 0;
}

void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------------------\n");
}

bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int colors[], int v, int c, int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && c == colors[i]) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true; // Safe to color
}

bool graphColorUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int colors[], int vertex, int vertices) {
    if (vertex == vertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, colors, vertex, c, vertices)) {
            colors[vertex] = c; // Assign color c to vertex
            if (graphColorUtil(graph, m, colors, vertex + 1, vertices)) {
                return true; // If successful, return true
            }
            colors[vertex] = 0; // Backtrack
        }
    }
    return false; // No color can be assigned
}

void solveGraphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int vertices) {
    int colors[MAX_VERTICES] = {0}; // Initialize color array

    if (graphColorUtil(graph, m, colors, 0, vertices)) {
        printf("Solution found! The colors assigned to the vertices are:\n");
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d --> Color %d\n", i, colors[i]);
        }
    } else {
        printf("No solution exists with the given number of colors.\n");
    }
}
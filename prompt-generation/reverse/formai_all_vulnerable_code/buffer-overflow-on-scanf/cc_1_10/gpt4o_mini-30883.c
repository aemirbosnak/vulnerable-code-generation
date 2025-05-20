//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10  // Maximum number of vertices

// Structure to represent a graph
typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numberOfVertices;
} Graph;

// Function to initialize the graph
void initializeGraph(Graph *g, int vertices) {
    g->numberOfVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0;  // Initialize all edges to 0
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph *g, int startVertex, int endVertex) {
    g->adjacencyMatrix[startVertex][endVertex] = 1;
    g->adjacencyMatrix[endVertex][startVertex] = 1;  // Undirected graph
}

// Function to check if the current color can be assigned to a vertex
bool isSafe(int vertex, Graph *g, int colors[], int color) {
    for (int i = 0; i < g->numberOfVertices; i++) {
        if (g->adjacencyMatrix[vertex][i] == 1 && colors[i] == color) {
            return false;  // An adjacent vertex has the same color
        }
    }
    return true;
}

// Utility function to solve the m-coloring problem
bool graphColoringUtil(Graph *g, int m, int colors[], int vertex) {
    if (vertex == g->numberOfVertices) {
        return true;  // All vertices are assigned a color
    }

    for (int color = 1; color <= m; color++) {
        if (isSafe(vertex, g, colors, color)) {
            colors[vertex] = color;  // Assign color to vertex

            if (graphColoringUtil(g, m, colors, vertex + 1)) {
                return true;
            }

            colors[vertex] = 0;  // Backtrack
        }
    }
    return false;  // No color can be assigned to this vertex
}

// Function to solve the graph coloring problem
void graphColoring(Graph *g, int m) {
    int colors[MAX_VERTICES] = {0};  // Initialize colors of vertices

    if (graphColoringUtil(g, m, colors, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < g->numberOfVertices; i++) {
            printf("Vertex %d -> Color %d\n", i + 1, colors[i]);
        }
    } else {
        printf("No solution exists\n");  // No valid coloring found
    }
}

// Main function to demonstrate graph coloring
int main() {
    Graph g;
    int vertices, edges, m;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initializeGraph(&g, vertices);

    // Input edges
    printf("Enter edges (start_vertex end_vertex):\n");
    for (int i = 0; i < edges; i++) {
        int startVertex, endVertex;
        scanf("%d %d", &startVertex, &endVertex);
        addEdge(&g, startVertex - 1, endVertex - 1); // Adjusting for 0-based index
    }

    // Input number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Call the graph coloring function
    graphColoring(&g, m);

    return 0;
}
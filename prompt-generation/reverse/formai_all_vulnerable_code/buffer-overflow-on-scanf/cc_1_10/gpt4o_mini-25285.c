//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50 // Maximum number of vertices in the graph

// Structure to represent a graph
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int numVertices; // Number of vertices
} Graph;

// Function to initialize a graph
void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0; // Initialize all edges to 0
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1; // Add edge from src to dest
    g->adjMatrix[dest][src] = 1; // Add edge from dest to src (undirected)
}

// Function to print the adjacency matrix
void printGraph(Graph g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            printf("%d ", g.adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to assign a color to a vertex
bool isSafe(int v, Graph g, int color[], int c) {
    for (int i = 0; i < g.numVertices; i++) {
        if (g.adjMatrix[v][i] && color[i] == c) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true; // Safe to color vertex
}

// Utility function to solve the graph coloring problem using backtracking
bool graphColoringUtil(Graph g, int m, int color[], int v) {
    if (v == g.numVertices) return true; // All vertices are colored

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, g, color, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the next vertex
            if (graphColoringUtil(g, m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack
        }
    }
    return false; // No solution found
}

// Function to solve the graph coloring problem
void graphColoring(Graph g, int m) {
    int color[MAX_VERTICES] = {0}; // Color array to store assigned colors

    if (graphColoringUtil(g, m, color, 0)) {
        printf("Coloring possible with %d colors:\n", m);
        for (int i = 0; i < g.numVertices; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("Coloring not possible with %d colors.\n", m);
    }
}

// Main function
int main() {
    Graph g;
    int vertices, edges, src, dest, m;

    // Input for the graph
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    initGraph(&g, vertices);

    printf("Enter edges (source and destination pairs):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    // Print the graph representation
    printGraph(g);

    // Solve the graph coloring problem
    graphColoring(g, m);

    return 0;
}
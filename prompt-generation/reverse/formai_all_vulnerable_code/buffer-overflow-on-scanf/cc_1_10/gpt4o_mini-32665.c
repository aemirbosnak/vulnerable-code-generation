//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct {
    int numVertices;
    bool adjacent[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a new graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize the adjacency matrix to false
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacent[i][j] = false;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacent[src][dest] = true;
    graph->adjacent[dest][src] = true; // Undirected graph
}

// Function to check if a color can be assigned to a vertex
bool isSafe(int vertex, Graph* graph, int color[], int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph->adjacent[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Function to solve the graph coloring problem using backtracking
bool graphColorUtil(Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->numVertices) {
        return true; // All vertices are processed
    }

    // Try different colors for vertex
    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, graph, color, c, graph->numVertices)) {
            color[vertex] = c; // Assign color c to vertex

            // Recursively try to color the rest of the vertices
            if (graphColorUtil(graph, m, color, vertex + 1)) {
                return true;
            }

            // Backtrack
            color[vertex] = 0;
        }
    }
    return false; // No color can be assigned
}

// Function to solve the graph coloring problem
bool graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (!graphColorUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        free(color);
        return false;
    }

    // Print the result
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }

    free(color);
    return true;
}

int main() {
    int numVertices, numEdges, m; // Number of vertices, edges, and colors
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);
    
    // Free the allocated memory
    free(graph);
    
    return 0;
}
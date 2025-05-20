//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100  // Maximum number of vertices

// A structure to represent a graph
typedef struct {
    int numVertices;
    int adjMatrix[MAX_V][MAX_V];
} Graph;

// Function to create a graph with the given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the undirected graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // Undirected graph
}

// Function to print the adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current color assignment is safe for vertex v
int isSafe(int v, Graph* graph, int* color, int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[v][i] == 1 && color[i] == c) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

// Function to solve the graph coloring problem using backtracking
int graphColoringUtil(Graph* graph, int m, int* color, int v) {
    if (v == graph->numVertices) {
        return 1; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color 'c' to vertex 'v'
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return 1; // If solution found
            }
            color[v] = 0; // Backtrack
        }
    }
    return 0; // No solution found
}

// Function to solve the graph coloring problem
void graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0; // Initialize all colors to 0 (no color)
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution found:\n");
        for (int i = 0; i < graph->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution not possible with %d colors.\n", m);
    }

    free(color);
}

// Main function to demonstrate the graph coloring
int main() {
    int vertices, edges, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices); // Accepts number of vertices
    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges); // Accepts number of edges

    printf("Enter edges in the format [source destination]:\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest); // Accept each edge
        addEdge(graph, src, dest);
    }

    printGraph(graph); // Print the created graph

    printf("Enter number of colors: ");
    scanf("%d", &m); // Accept number of colors

    graphColoring(graph, m); // Perform graph coloring

    free(graph); // Cleanup
    return 0;
}
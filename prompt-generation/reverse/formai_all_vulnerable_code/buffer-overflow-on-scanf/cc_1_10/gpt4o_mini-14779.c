//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INFINITY 10000

// Structure to represent an edge and its weight
typedef struct {
    int src, dest;
} Edge;

// Graph structure
typedef struct {
    int numVertices;
    Edge edges[MAX_VERTICES];
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->edges[i].src = -1;
        graph->edges[i].dest = -1;
    }
    return graph;
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest, int index) {
    graph->edges[index].src = src;
    graph->edges[index].dest = dest;
}

// Function to check if the current color assignment is safe for vertex v
int isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the m-coloring problem using backtracking
int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int vertex, int vertices) {
    if (vertex == vertices) {
        return 1;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, graph, color, c, vertices)) {
            color[vertex] = c;
            if (graphColoringUtil(graph, m, color, vertex + 1, vertices)) {
                return 1;
            }
            color[vertex] = 0; // Backtrack
        }
    }
    return 0;
}

// Function to solve the graph coloring problem
void graphColoring(Graph* graph, int m) {
    int color[MAX_VERTICES] = {0};
    int vertices = graph->numVertices;

    if (graphColoringUtil(graph->edges, m, color, 0, vertices)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists.\n");
    }
}

// Main function
int main() {
    int numVertices, m;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    
    Graph* graph = createGraph(numVertices);
    
    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Use the graph's adjacency matrix to find color assignments
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->edges[i * numVertices + j].src = i;
            graph->edges[i * numVertices + j].dest = j;
        }
    }

    graphColoring(graph, m);
    
    // Clean up memory
    free(graph);
    return 0;
}
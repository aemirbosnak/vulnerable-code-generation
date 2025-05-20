//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

// Structure to represent a graph
typedef struct Graph {
    int V; // Number of vertices
    int **adj; // Adjacency matrix
} Graph;

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (int**)malloc(V * sizeof(int*));

    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)calloc(V, sizeof(int));
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // For undirected graph
}

// Function to check if the current color assignment is safe for vertex v
int isSafe(Graph* graph, int v, int color[], int col) {
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] == 1 && color[i] == col) {
            return 0;
        }
    }
    return 1;
}

// Backtracking function to assign colors to vertices
int graphColoringUtil(Graph* graph, int m, int color[], int v) {
    if (v == graph->V) {
        return 1; // All vertices colored
    }

    for (int col = 1; col <= m; col++) {
        if (isSafe(graph, v, color, col)) {
            color[v] = col;

            if (graphColoringUtil(graph, m, color, v + 1)) {
                return 1;
            }

            color[v] = 0; // Backtrack
        }
    }
    return 0; // No solution found
}

// Function to solve the graph coloring problem
void graphColoring(Graph* graph, int m) {
    int *color = (int*)calloc(graph->V, sizeof(int));

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < graph->V; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists\n");
    }

    free(color);
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);
}

// Main function
int main() {
    int V, E, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);
    
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (format: src dest):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the maximum number of colors: ");
    scanf("%d", &m);
    
    graphColoring(graph, m);
    freeGraph(graph);
    
    return 0;
}
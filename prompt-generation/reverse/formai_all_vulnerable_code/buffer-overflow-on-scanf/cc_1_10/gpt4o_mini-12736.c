//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure to represent a graph
typedef struct {
    int vertices;
    int adj[MAX_NODES][MAX_NODES];
} Graph;

// Function to create an empty graph with given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0; // Initialize all edges to 0
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // Undirected graph
}

// Function to display the current state of the graph
void displayGraph(Graph* graph) {
    printf("Graph Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current color assignment is safe for vertex v
bool isSafe(Graph* graph, int v, int color[], int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Utility function to solve the graph coloring problem
bool graphColoringUtil(Graph* graph, int m, int color[], int v) {
    // Base case: If all vertices are assigned a color
    if (v == graph->vertices) {
        return true;
    }

    // Trying to color vertex v with different colors
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, v, color, c)) {
            color[v] = c; // Assign color

            // Recursively assign colors to the next vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // If no color can be assigned, remove the color (backtrack)
            color[v] = 0;
        }
    }
    return false;
}

// Main function to solve the graph coloring problem
void graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Coloring of graph possible with %d colors:\n", m);
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d => Color %d\n", i, color[i]);
        }
    } else {
        printf("Coloring of graph is not possible with %d colors.\n", m);
    }

    free(color);
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    free(graph);
}

// Entry point of the program
int main() {
    int vertices, edges, m;
    printf("Welcome to the Graph Coloring Problem Solver!\n");
    printf("Please enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Please enter the number of edges: ");
    scanf("%d", &edges);
    printf("Please enter the number of colors: ");
    scanf("%d", &m);
    
    Graph* graph = createGraph(vertices);

    printf("Enter edges (format: source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    displayGraph(graph);
    graphColoring(graph, m);
    freeGraph(graph);
    return 0;
}
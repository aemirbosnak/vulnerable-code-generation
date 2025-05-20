//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// A structure to represent a graph
struct Graph {
    int numVertices;
    int** adjMatrix;
};

// Function to create a graph with a specified number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Initialize adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// Function to print the adjacency matrix of the graph
void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it is safe to assign a color to a vertex
int isSafe(int vertex, int color[], int c, struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && color[i] == c) {
            return 0; // Not safe
        }
    }
    return 1; // Safe to assign color
}

// Utility function to solve the graph coloring problem
int graphColoringUtil(struct Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->numVertices) {
        return 1; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, color, c, graph)) {
            color[vertex] = c; // Assign color

            // Recur to assign colors to the remaining vertices
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return 1;
            }

            color[vertex] = 0; // Backtrack
        }
    }
    return 0; // No solution
}

// Function to solve the graph coloring problem
void graphColoring(struct Graph* graph, int m) {
    int* color = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0; // Initialize all vertices as unassigned
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution Exists: Following are the assigned colors:\n");
        for (int i = 0; i < graph->numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("No Solution Exists\n");
    }

    free(color);
}

// Driver program to test above functions
int main() {
    int vertices, edges, src, dest, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (src dest): \n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);

    // Free memory
    for (int i = 0; i < vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}
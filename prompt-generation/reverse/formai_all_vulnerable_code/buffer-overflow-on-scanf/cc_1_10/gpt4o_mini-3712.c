//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function to initialize the graph
void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0; // No edges initially
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices) {
        printf("Vertex index out of bounds\n");
        return;
    }
    g->adjacencyMatrix[src][dest] = 1; // For a directed graph
}

// Function to remove an edge from the graph
void removeEdge(Graph* g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices) {
        printf("Vertex index out of bounds\n");
        return;
    }
    g->adjacencyMatrix[src][dest] = 0; // Remove the edge
}

// Function to print the graph
void printGraph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search
void DFS(Graph* g, int vertex, int* visited) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex); // Print the vertex

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited); // Recur for connected vertices
        }
    }
}

// Function to perform Breadth First Search
void BFS(Graph* g, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[start] = 1;
    queue[++rear] = start;

    printf("\nBFS starting from vertex %d:\n", start);
    while (front != rear) {
        front++;
        int current = queue[front];
        printf("%d ", current);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjacencyMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i; // Add to the queue
            }
        }
    }
}

// Main function
int main() {
    Graph g;
    int numVertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    initGraph(&g, numVertices);

    // Creating a sample graph
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 0);

    // Print the adjacency matrix
    printGraph(&g);

    // Perform Depth First Search
    printf("DFS starting from vertex 0:\n");
    int visited[MAX_VERTICES] = {0};
    DFS(&g, 0, visited);
    printf("\n");

    // Perform Breadth First Search
    BFS(&g, 0);

    // Clean up memory and exit
    return 0;
}
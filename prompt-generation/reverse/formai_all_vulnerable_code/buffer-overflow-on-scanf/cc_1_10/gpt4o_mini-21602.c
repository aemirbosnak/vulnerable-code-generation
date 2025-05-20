//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // No edges initially
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int startVertex, int endVertex) {
    graph->adjMatrix[startVertex][endVertex] = 1; // Mark the edge
    graph->adjMatrix[endVertex][startVertex] = 1; // Mark the edge for undirected graph
}

// Function to display the adjacency matrix
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix of the Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function for Depth First Search
void DFS(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the vertex as visited
    printf("%d ", vertex); // Print the vertex

    // Traverse all adjacent vertices
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited); // Recursive call
        }
    }
}

// Function to initiate DFS
void startDFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to track visited vertices
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex, visited);
    printf("\n");
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    free(graph);
}

// Main function to demonstrate the graph
int main() {
    int vertices, edges;
    printf("Welcome to the Graph Representation Program!\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        int startVertex, endVertex;
        printf("Enter edge %d (start and end vertices): ", i + 1);
        scanf("%d %d", &startVertex, &endVertex);
        addEdge(graph, startVertex, endVertex);
    }

    displayGraph(graph);

    int startVertex;
    printf("Enter a vertex to start DFS: ");
    scanf("%d", &startVertex);
    
    startDFS(graph, startVertex);

    freeGraph(graph);
    printf("Thank you for using the program! Goodbye!\n");
    
    return 0;
}
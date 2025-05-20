//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices in the graph

// Structure to represent a graph
typedef struct Graph {
    int numVertices;                    // Number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

// Function to create a new graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // 0 means no edge
        }
    }

    return graph;
}

// Funtion to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Set the edge from src to dest
    graph->adjMatrix[dest][src] = 1; // Since it is an undirected graph
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph* graph) {
    printf("The adjacency matrix of the graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a depth-first search
void DFS(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true; // Mark the current vertex as visited
    printf("Visited vertex: %d\n", vertex);
    
    for (int i = 0; i < graph->numVertices; i++) {
        // If there is an edge and it has not been visited
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited); // Recur for the adjacent vertex
        }
    }
}

// Function to start the depth-first search
void startDFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false}; // Array to track visited vertices
    DFS(graph, startVertex, visited);
}

// Main function to drive the program
int main() {
    printf("🎉 Let's create a cheerful graph! 🎉\n");
    
    int vertices;
    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    // Ensure we don't exceed the maximum vertex limit
    if (vertices < 1 || vertices > MAX_VERTICES) {
        printf("Oops! The number of vertices must be between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }

    Graph* graph = createGraph(vertices);

    // Adding edges cheerfully
    printf("🎈 Let's add some cheerful edges to our graph! 🎈\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            char choice;
            printf("Would you like to add an edge between vertex %d and vertex %d? (y/n): ", i, j);
            scanf(" %c", &choice);
            if (choice == 'y') {
                addEdge(graph, i, j);
                printf("✨ Edge added between vertex %d and vertex %d! ✨\n", i, j);
            }
        }
    }

    // Print the lovely adjacency matrix
    printGraph(graph);

    // Start a cheerful DFS
    int startVertex;
    printf("Which vertex would you like to start the DFS from (0 to %d)? ", vertices - 1);
    scanf("%d", &startVertex);
    if (startVertex < 0 || startVertex >= vertices) {
        printf("😢 Sorry, please choose a valid starting vertex between 0 and %d.\n", vertices - 1);
        free(graph);
        return 1;
    }

    printf("🌟 Starting Depth-First Search from vertex %d! 🌟\n", startVertex);
    startDFS(graph, startVertex);

    // Free the allocated memory
    free(graph);
    printf("🎊 Thank you for exploring the graph with us! 🎊\n");
    
    return 0;
}
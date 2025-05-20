//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX 20 // Maximum number of vertices
#define INF 99999 // Infinity value for unreachable edges

// Structure to represent a graph
typedef struct {
    int vertices; // Number of vertices
    int adjMatrix[MAX][MAX]; // Adjacency matrix
} Graph;

// Function to create a graph with a given number of vertices
Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j)
                graph->adjMatrix[i][j] = 0; // Distance to self is zero
            else
                graph->adjMatrix[i][j] = INF; // Initially set to infinity
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight; // Add edge from src to dest
    graph->adjMatrix[dest][src] = weight; // Add edge from dest to src (for undirected graph)
}

// Function to display the adjacency matrix
void printGraph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Dijkstra's algorithm to find the shortest path
void dijkstra(Graph *graph, int startVertex) {
    int visited[MAX] = {0}; // Mark all vertices as not visited
    int distance[MAX]; // Array to hold the shortest distance from startVertex
    
    // Initialize distances
    for (int i = 0; i < graph->vertices; i++) {
        distance[i] = graph->adjMatrix[startVertex][i];
    }
    visited[startVertex] = 1; // Mark the starting vertex as visited
    
    for (int count = 0; count < graph->vertices - 1; count++) {
        // Find the minimum distance vertex
        int minDistance = INF, minIndex;

        for (int v = 0; v < graph->vertices; v++) {
            if (!visited[v] && distance[v] < minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }
        visited[minIndex] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < graph->vertices; v++) {
            if (!visited[v] && graph->adjMatrix[minIndex][v] != INF) {
                if (minDistance + graph->adjMatrix[minIndex][v] < distance[v]) {
                    distance[v] = minDistance + graph->adjMatrix[minIndex][v];
                }
            }
        }
    }

    // Print the distances
    printf("Vertex Distance from Source (%d):\n", startVertex);
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: %d\n", i, distance[i]);
    }
}

// Main function to demonstrate the graph functionalities
int main() {
    int vertices, edges, src, dest, weight;

    printf("Welcome to the Curious Graph Program!\n");
    printf("How many vertices does your graph have? (Max %d): ", MAX);
    scanf("%d", &vertices);
    
    if (vertices <= 0 || vertices > MAX) {
        printf("Please enter a valid number of vertices.\n");
        return 1;
    }

    Graph *graph = createGraph(vertices);

    printf("How many edges do you want to add? ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter source, destination and weight for edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        
        if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
            printf("Invalid vertices! Please make sure they are in range [0, %d).\n", vertices);
            i--; // Repeat this edge input
            continue;
        }

        addEdge(graph, src, dest, weight);
    }

    printGraph(graph);

    printf("Now, let's find the shortest paths from a starting vertex.\n");
    printf("Enter the starting vertex (0 to %d): ", vertices - 1);
    int startVertex;
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    dijkstra(graph, startVertex);

    // Free allocated memory
    free(graph);
    printf("Thank you for using the Curious Graph Program. Happy Graphing!\n");
    return 0;
}
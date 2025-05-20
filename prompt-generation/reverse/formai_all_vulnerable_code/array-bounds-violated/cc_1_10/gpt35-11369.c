//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM_VERTICES 100
#define MAXIMUM_EDGES 1000

// Data structure to represent a Graph
typedef struct Graph {
    int verticesCount;
    int edgesCount;
    int adjacencyMatrix[MAXIMUM_VERTICES][MAXIMUM_VERTICES];
} Graph;

// Function to read in an integer from the user
int readInput() {
    int input;
    printf("Enter an integer: ");
    scanf("%d", &input);
    return input;
}

// Function to check if an edge can be added between two vertices
int validEdge(Graph graph, int vertex1, int vertex2, int color[]) {
    for (int i = 0; i < graph.verticesCount; i++) {
        if (graph.adjacencyMatrix[vertex1][i] == 1 && color[i] == color[vertex2]) return 0; // the edge already exists with the same color
    }
    return 1;
}

// Function to color the graph vertices
int graphColoring(Graph graph, int vertexCount) {
    int color[vertexCount];
    for (int i = 0; i < vertexCount; i++) color[i] = 0; // Initialize all colors to 0

    // Start with the first vertex and color it with the first color
    color[0] = 1;

    // Go through the remaining vertices and color them
    for (int i = 1; i < vertexCount; i++) {
        color[i] = 0; // Initialize the color to 0
        
        // Check all the colors that have been used on the neighbors and choose a color that has not been used
        for (int j = 0; j < vertexCount; j++) {
            if (graph.adjacencyMatrix[i][j] == 1 && color[j] != 0) {
                color[i] = color[j];
                break;
            }
        }
        
        // If we were not able to find a color that has not been used, use a new color
        if (color[i] == 0) {
            int availableColors[vertexCount];
            for (int j = 0; j < vertexCount; j++) {
                availableColors[j] = 1; // Initialize all colors to available
            }

            for (int j = 0; j < vertexCount; j++) {
                if (graph.adjacencyMatrix[i][j] == 1 && color[j] != 0) {
                    availableColors[color[j]] = 0;
                }
            }
            for (int j = 1; j <= vertexCount; j++) {
                if (availableColors[j] == 1) {
                    color[i] = j;
                    break;
                }
            }
        }
    }
    printf("The colors assigned to the vertices are: \n");
    for (int i = 0; i < vertexCount; i++) printf("%d ", color[i]);
    printf("\n");
}

int main() {
    Graph graph;
    graph.verticesCount = readInput();
    graph.edgesCount = readInput();

    // Initialize the adjacency matrix to all zeros
    for (int i = 0; i < graph.verticesCount; i++) {
        for (int j = 0; j < graph.verticesCount; j++) {
            graph.adjacencyMatrix[i][j] = 0;
        }
    }

    // Read in the edges and populate the adjacency matrix
    for (int i = 0; i < graph.edgesCount; i++) {
        int vertex1 = readInput();
        int vertex2 = readInput();
        graph.adjacencyMatrix[vertex1][vertex2] = 1;
        graph.adjacencyMatrix[vertex2][vertex1] = 1;

        // Check if the edge is valid, if not, print an error message and exit the program
        int color[MAXIMUM_VERTICES];
        if (!validEdge(graph, vertex1, vertex2, color)) {
            printf("Error: Edge cannot be added.\n");
            exit(0);
        }
    }

    // Color the graph vertices and print the result
    graphColoring(graph, graph.verticesCount);
    return 0;
}
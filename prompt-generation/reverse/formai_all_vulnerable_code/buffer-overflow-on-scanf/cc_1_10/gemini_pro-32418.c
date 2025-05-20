//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 5
#define MAX_VERTICES 100

int numColors;
int colors[MAX_VERTICES];
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

// Function to check if a vertex can be colored with a given color
int isSafe(int vertex, int color) {
    for (int i = 0; i < numColors; i++) {
        if (adjacencyMatrix[vertex][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Function to color a vertex with a given color
void colorVertex(int vertex, int color) {
    colors[vertex] = color;
}

// Function to find a valid coloring for the graph
int graphColoring(int vertex) {
    // If all vertices have been colored, return true
    if (vertex == numColors) {
        return 1;
    }

    // Try all possible colors for the current vertex
    for (int color = 0; color < numColors; color++) {
        // If the vertex can be colored with the current color, color it and recursively color the next vertex
        if (isSafe(vertex, color)) {
            colorVertex(vertex, color);
            if (graphColoring(vertex + 1)) {
                return 1;
            }
            // If the coloring is not valid, reset the color of the current vertex
            colorVertex(vertex, -1);
        }
    }

    // If no valid coloring can be found, return false
    return 0;
}

int main() {
    // Get the number of vertices and edges in the graph
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges in the graph: ");
    scanf("%d %d", &numVertices, &numEdges);

    // Get the adjacency matrix of the graph
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Get the number of colors to use
    printf("Enter the number of colors to use: ");
    scanf("%d", &numColors);

    // Initialize the colors array to -1
    for (int i = 0; i < numVertices; i++) {
        colors[i] = -1;
    }

    // Check if the graph can be colored with the given number of colors
    if (graphColoring(0)) {
        printf("The graph can be colored with %d colors:\n", numColors);
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors.\n", numColors);
    }

    return 0;
}
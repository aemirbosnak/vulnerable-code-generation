//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
// Include required libraries
#include <stdio.h>
#include <stdlib.h>

// Define max size for the graph
#define MAX_SIZE 100

// Function to assign colors to vertices
void assignColors(int graph[MAX_SIZE][MAX_SIZE], int vertexCount, int maxColors) {
    // Store the assigned colors
    int colors[MAX_SIZE];

    // Assign the first vertex the first color
    colors[0] = 1;

    // Loop through the remaining vertices and assign colors
    for(int i=1; i<vertexCount; i++) {
        // Mark all the colors as available
        int availableColors[MAX_SIZE] = {0};

        // Check the colors assigned to adjacent vertices
        for(int j=0; j<i; j++) {
            if(graph[i][j]) {
                // If the adjacent vertex is already assigned a color, mark it as unavailable
                if(colors[j] != 0) {
                    availableColors[colors[j]] = 1;
                }
            }
        }

        // Assign the first available color to the vertex
        for(int j=1; j<=maxColors; j++) {
            if(availableColors[j] == 0) {
                colors[i] = j;
                break;
            }
        }
    }

    // Print the assigned colors
    printf("Assigned colors:\n");
    for(int i=0; i<vertexCount; i++) {
        printf("Vertex %d: Color %d\n", i+1, colors[i]);
    }
}

// Main function
int main() {
    // Get user input for the vertex count and maximum colors
    int vertexCount, maxColors;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertexCount);
    printf("Enter the maximum number of colors: ");
    scanf("%d", &maxColors);

    // Define the graph as a 2D array
    int graph[MAX_SIZE][MAX_SIZE];
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<vertexCount; i++) {
        for(int j=0; j<vertexCount; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Assign colors to the vertices and print the result
    assignColors(graph, vertexCount, maxColors);

    return 0;
}
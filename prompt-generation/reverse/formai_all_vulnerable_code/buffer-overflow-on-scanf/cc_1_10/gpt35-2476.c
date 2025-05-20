//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10 // Maximum number of vertices

int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix

int vertices[MAX_VERTICES]; // Array to store the colors of vertices
bool selected[MAX_VERTICES]; // Array to keep track of the selected vertices

int num_vertices; // Number of vertices in the graph


// Function to check if the given color can be assigned to the given vertex
bool isColorPossible(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && vertices[i] == color)
            return false;
    }
    return true;
}

// Function to assign colors to vertices
bool assignColors(int vertex) {
    if (vertex == num_vertices) // Base case: All vertices are assigned a color
        return true;

    for (int color = 1; color <= num_vertices; color++) {
        if (isColorPossible(vertex, color)) {
            vertices[vertex] = color; // Assign the color
            if (assignColors(vertex + 1)) // Move to the next vertex
                return true;
            vertices[vertex] = 0; // Backtrack: Reset the color of the current vertex
        }
    }
    return false; // No solution found
}

// Function to print the colors of the vertices
void printVertices() {
    printf("Vertices are colored as follows:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, vertices[i]);
    }
}

int main() {
    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize the colors of vertices to 0 (unassigned)
    for (int i = 0; i < num_vertices; i++) {
        vertices[i] = 0;
        selected[i] = false;
    }

    // Call the assignColors function to assign colors to vertices
    bool isSuccess = assignColors(0);

    if (isSuccess)
        printVertices();
    else
        printf("Graph cannot be colored.\n");

    return 0;
}
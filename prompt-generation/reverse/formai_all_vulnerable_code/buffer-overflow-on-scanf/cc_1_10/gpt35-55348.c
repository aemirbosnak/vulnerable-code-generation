//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print adjacency matrix
void printAdjMatrix(int adjMatrix[50][50], int vertices) {
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a vertex v can be assigned color c
bool isAllowed(int adjMatrix[50][50], int vertices, int colors[], int v, int c) {
    for(int i=0; i<vertices; i++) {
        if(adjMatrix[v][i] && c==colors[i]) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve graph coloring problem
bool solveGraphColoring(int adjMatrix[50][50], int vertices, int colors[], int v) {
    if(v==vertices) {
        return true;
    }
    for(int i=1; i<=vertices; i++) {
        if(isAllowed(adjMatrix, vertices, colors, v, i)) {
            colors[v] = i;
            if(solveGraphColoring(adjMatrix, vertices, colors, v+1)) {
                return true;
            }
            colors[v] = 0;
        }
    }
    return false;
}

int main() {
    // Inputting the number of vertices
    int vertices;
    scanf("%d", &vertices);

    // Creating adjacency matrix
    int adjMatrix[50][50];
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Print adjacency matrix
    printf("Adjacency Matrix:\n");
    printAdjMatrix(adjMatrix, vertices);

    // Initializing all colors to 0
    int colors[50] = {0};

    // Solving graph coloring problem
    if(solveGraphColoring(adjMatrix, vertices, colors, 0)) {
        // Print the color assigned to each vertex
        printf("Vertices colors:\n");
        for(int i=0; i<vertices; i++) {
            printf("Vertex %d: Color %d\n", i+1, colors[i]);
        }
    }
    else {
        printf("The graph cannot be colored with %d colors.", vertices);
    }

    return 0;
}
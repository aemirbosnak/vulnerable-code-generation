//FormAI DATASET v1.0 Category: Graph representation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

/*
This program demonstrates a unique way to represent a graph using an adjacency matrix.
The program first initializes the graph with a user-defined number of vertices, and then
prompts the user to input the edges connecting the vertices. The edges are stored in the
adjacency matrix, and then the program prints the matrix to the console.
*/

// Function to print the adjacency matrix
void printMatrix(int **matrix, int n) {
    printf("\n===========================================");
    printf("\nAdjacency Matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("===========================================\n");
}

int main() {
    int n, e, v1, v2;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Dynamically allocate memory for a 2D array
    int **adjMatrix = (int**)malloc(n * sizeof(int*));
    for(int i=0;i<n;i++) {
        adjMatrix[i] = (int*)malloc(n * sizeof(int));
        // Initialize all cells to 0
        for(int j=0;j<n;j++) {
            adjMatrix[i][j] = 0;
        }
    }
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);
    for(int i=0;i<e;i++) {
        printf("Enter the vertices of edge %d: ", i+1);
        scanf("%d %d", &v1, &v2);
        // Update the adjacency matrix with the edge connection
        adjMatrix[v1-1][v2-1] = 1;
        adjMatrix[v2-1][v1-1] = 1;
    }
    // Print the adjacency matrix
    printMatrix(adjMatrix, n);
    // Free the dynamically allocated memory
    for(int i=0;i<n;i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    printf("\n");
    return 0;
}
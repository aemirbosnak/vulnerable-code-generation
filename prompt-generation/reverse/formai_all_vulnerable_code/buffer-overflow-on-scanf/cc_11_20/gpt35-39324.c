//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>

// Define the maximum number of vertices allowed for the graph
#define MAX_VERTICES 20

int main() {
    int vertices, edges;

    // Ask the user how many vertices the graph will have
    printf("How many vertices will the graph have? (Maximum is %d)\n", MAX_VERTICES);
    scanf("%d", &vertices);

    // Ensure the entered number of vertices is valid
    if (vertices > MAX_VERTICES) {
        printf("Sorry, the maximum number of vertices allowed for this graph is %d.\n", MAX_VERTICES);
        return 0;
    }

    // Ask the user how many edges the graph will have
    printf("How many edges will the graph have?\n");
    scanf("%d", &edges);

    // Create the adjacency matrix for the graph and initialize all values to 0
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    // Ask the user to enter the edges between vertices
    printf("Enter the edges between vertices (e.g. 1 2 for an edge between vertex 1 and 2):\n");
    for (int i = 0; i < edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);

        // Ensure that the entered edges are valid
        if (vertex1 < 1 || vertex1 > vertices || vertex2 < 1 || vertex2 > vertices) {
            printf("Sorry, the entered edge is invalid.\n");
            continue;
        }

        // Add the edge to the adjacency matrix
        adjacency_matrix[vertex1 - 1][vertex2 - 1] = 1;
        adjacency_matrix[vertex2 - 1][vertex1 - 1] = 1;
    }

    // Print the graph in a unique format
    printf("\n\n      ");
    for (int i = 1; i <= vertices; i++) {
        printf("%5d", i);
    }
    printf("\n");
    for (int i = 0; i <= vertices; i++) {
        printf("=====");
    }
    printf("\n");
    for (int i = 0; i < vertices; i++) {
        printf("%5d|", i + 1);
        for (int j = 0; j < vertices; j++) {
            if (adjacency_matrix[i][j] == 1) {
                printf("%5c", 'X');
            } else {
                printf("%5c", ' ');
            }
        }
        printf("\n");
    }

    return 0;
}
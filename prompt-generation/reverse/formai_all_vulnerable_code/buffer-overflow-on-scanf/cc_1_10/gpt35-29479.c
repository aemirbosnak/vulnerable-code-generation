//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>

// Function to print the adjacency matrix
void printGraph(int adjMatrix[][10], int vertices) {
    printf("Adjacency matrix:\n\n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, adjMatrix[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the adjacency matrix with 0
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Add edges to the graph
    int choice = 0, src = 0, dest = 0;
    while(choice != -1) {
        printf("\nEnter source vertex (0 – %d): ", vertices-1);
        scanf("%d", &src);
        printf("Enter destination vertex (0 – %d): ", vertices-1);
        scanf("%d", &dest);

        if(src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1;
        }
        else {
            printf("Please enter valid vertex numbers (0 – %d).\n", vertices-1);
        }

        printf("\nEnter -1 to stop adding more edges or any other number to continue: ");
        scanf("%d", &choice);
    }

    // Print the adjacency matrix
    printGraph(adjMatrix, vertices);

    return 0;
}
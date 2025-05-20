//FormAI DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>

// Function to print the graph
void printGraph(int adjMatrix[][10], int n) {
    printf("Adjacency Matrix:\n\n");
    printf("    ");
    for(int i=0; i<n; i++){
        printf("| %d ",i);
    }
    printf("|\n");
    for(int i=0; i<=n; i++){
        printf("----");
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d | ",i);
        for(int j=0; j<n; j++){
            printf("%d  ",adjMatrix[i][j]);
        }
        printf("\n");
     }
}

int main() {
    int n, adjMatrix[10][10];
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Initialize the adjacency matrix
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Add edges to the graph
    printf("\nEnter the number of edges in the graph: ");
    int m;
    scanf("%d", &m);
    printf("\nEnter the edges:\n");
    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Call printGraph function
    printGraph(adjMatrix, n);

    return 0;
}
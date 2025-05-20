//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

struct Edge {
    int src;
    int dest;
};

int main() {
    int i, j, numVertices, numEdges, choice;
    bool matrix[MAX_VERTICES][MAX_VERTICES] = {0};
    struct Edge edgeList[MAX_VERTICES];
    
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    
    printf("Enter edges (src dest):\n");
    for (i = 0; i < numEdges; i++) {
        scanf("%d %d", &edgeList[i].src, &edgeList[i].dest);
        matrix[edgeList[i].src][edgeList[i].dest] = true;
    }
    
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    while (true) {
        printf("\nEnter source vertex to see its neighbors (press -1 to exit): ");
        scanf("%d", &choice);
        if (choice == -1) {
            break;
        } else if (choice < 0 || choice >= numVertices) {
            printf("Invalid vertex index!\n");
        } else {
            printf("Neighbors of vertex %d: ", choice);
            for (i = 0; i < numVertices; i++) {
                if (matrix[choice][i]) {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}
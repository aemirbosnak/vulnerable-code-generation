//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

int numVertices;
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int colorArray[MAX_VERTICES];

int isSafe(int vertex, int color) {
    for(int i=0; i<numVertices; i++) {
        if(adjMatrix[vertex][i] && colorArray[i]==color) {
            return 0;
        }
    }
    return 1;
}

int graphColoring(int vertex) {
    if(vertex == numVertices) {
        return 1;
    }

    for(int color=1; color<=numVertices; color++) {
        if(isSafe(vertex, color)) {
            colorArray[vertex] = color;

            if(graphColoring(vertex+1)) {
                return 1;
            }

            colorArray[vertex] = 0;
        }
    }

    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter adjacency matrix:\n");
    for(int i=0; i<numVertices; i++) {
        for(int j=0; j<numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    if(graphColoring(0) == 0) {
        printf("No solution exists.\n");
        exit(0);
    }

    printf("Graph can be colored using the following colors:\n");
    for(int i=0; i<numVertices; i++) {
        printf("Vertex %d: Color %d\n", i+1, colorArray[i]);
    }

    return 0;
}
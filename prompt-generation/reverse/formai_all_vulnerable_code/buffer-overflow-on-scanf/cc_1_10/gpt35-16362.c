//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 1000

struct Graph {
    int numVertices;
    int numColors;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void printColors(int colors[], int numVertices) {
    printf("The colors for each vertex are:\n");
    for(int i=0; i<numVertices; i++) {
        printf(" %d ", colors[i]);
    }
}

int isSafe(int v, int color, int colors[], struct Graph* graph) {
    for(int i=0; i<graph->numVertices; i++) {
        if(graph->adjMatrix[v][i] && color == colors[i]) {
            return 0;
        }
    }
    return 1;
}

int graphColorUtil(struct Graph* graph, int numColors, int colors[], int vertex) {
    if(vertex == graph->numVertices) {
        return 1;
    }
    for(int color=1; color<=numColors; color++) {
        if(isSafe(vertex, color, colors, graph)) {
            colors[vertex] = color;
            if(graphColorUtil(graph, numColors, colors, vertex+1)) {
                return 1;
            }
            colors[vertex] = 0;
        }
    }
    return 0;
}

int graphColoring(struct Graph* graph, int numColors) {
    int colors[MAX_VERTICES] = {0};
    if(graphColorUtil(graph, numColors, colors, 0)) {
        printColors(colors, graph->numVertices);
        return 1;
    }
    else {
        printf("No solution possible with %d colors.\n", numColors);
        return 0;
    }
}

int main() {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    printf("Enter the number of vertices: \n");
    scanf("%d", &graph->numVertices);
    printf("Enter the adjacency matrix: \n");
    for(int i=0; i<graph->numVertices; i++) {
        for(int j=0; j<graph->numVertices; j++) {
            scanf("%d", &graph->adjMatrix[i][j]);
        }
    }
    printf("Enter the number of colors: \n");
    scanf("%d", &graph->numColors);
    if(graphColoring(graph, graph->numColors)) {
        printf("Solution is possible with %d colors.\n", graph->numColors);
    }
    free(graph);
    return 0;
}
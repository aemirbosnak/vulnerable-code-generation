//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10
#define MAX_EDGES 200

int numVertices;
int numColors;
int numEdges;
int **graph;
int *colors;

void initGraph(void) {
    srand(time(NULL));
    numVertices = rand() % MAX_VERTICES + 1;
    numColors = rand() % MAX_COLORS + 1;
    numEdges = rand() % MAX_EDGES + 1;

    graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = rand() % 2;
        }
    }

    colors = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        colors[i] = rand() % numColors;
    }
}

void printGraph(void) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j]) {
                printf("%d -- %d\n", i, j);
            }
        }
    }
    printf("\n");
}

void printColors(void) {
    for (int i = 0; i < numVertices; i++) {
        printf("%d: %d\n", i, colors[i]);
    }
    printf("\n");
}

int isValid(int vertex, int color) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void colorGraph(void) {
    for (int i = 0; i < numVertices; i++) {
        int color = rand() % numColors;
        while (!isValid(i, color)) {
            color = rand() % numColors;
        }
        colors[i] = color;
    }
}

int main(void) {
    initGraph();
    printf("Graph:\n");
    printGraph();
    printf("Colors:\n");
    printColors();
    colorGraph();
    printf("Colored Graph:\n");
    printGraph();
    return 0;
}
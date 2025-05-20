//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int numVertices;
int **adjMatrix;
int *colors;

void initGraph() {
    srand(time(NULL));
    numVertices = rand() % MAX_VERTICES + 1;
    adjMatrix = (int **)malloc(sizeof(int *) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = (int *)malloc(sizeof(int) * numVertices);
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = rand() % 2;
        }
    }
    colors = (int *)malloc(sizeof(int) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        colors[i] = -1;
    }
}

void printGraph(int vertex) {
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void printColor(int vertex, int color) {
    printf("%d -> %d\n", vertex, color);
}

int isSafe(int vertex, int color, int v) {
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[v][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int colorGraph() {
    int startVertex = rand() % numVertices;
    colors[startVertex] = rand() % MAX_COLORS + 1;
    for (int i = 0; i < numVertices; i++) {
        if (colors[i] == -1) {
            int color = rand() % MAX_COLORS + 1;
            while (!isSafe(i, color, startVertex)) {
                color = (color + 1) % MAX_COLORS;
            }
            colors[i] = color;
            printColor(i, color);
        }
    }
    return 1;
}

int main() {
    initGraph();
    colorGraph();
    return 0;
}
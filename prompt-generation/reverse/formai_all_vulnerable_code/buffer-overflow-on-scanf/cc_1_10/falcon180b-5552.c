//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int numVertices;
int numColors;

void initializeGraph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void generateRandomGraph(int vertices) {
    srand(time(NULL));
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i!= j) {
                graph[i][j] = rand() % 2;
            }
        }
    }
}

void printGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void colorGraph(int vertices, int colors) {
    numColors = colors;
    for (int i = 0; i < vertices; i++) {
        color[i] = rand() % numColors;
    }
}

void printColoredGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", color[i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int vertices, colors;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &colors);

    initializeGraph(vertices);
    generateRandomGraph(vertices);
    colorGraph(vertices, colors);
    printGraph(vertices);
    printColoredGraph(vertices);

    return 0;
}
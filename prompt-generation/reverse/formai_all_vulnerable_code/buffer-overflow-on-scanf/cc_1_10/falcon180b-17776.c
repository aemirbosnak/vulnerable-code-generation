//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int nVertices, nColors;
int color[MAX_VERTICES];

void initializeGraph() {
    int i, j;
    for (i = 0; i < nVertices; i++) {
        for (j = 0; j < nVertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void readGraph() {
    int i, j, k;
    for (i = 0; i < nVertices; i++) {
        for (j = 0; j < nVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void printGraph() {
    int i, j;
    for (i = 0; i < nVertices; i++) {
        for (j = 0; j < nVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void printSolution() {
    int i;
    for (i = 0; i < nVertices; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

void backtrack(int v, int c) {
    int i;
    for (i = 0; i < nVertices; i++) {
        if (graph[v][i] == 1 && color[i] == -1) {
            color[i] = c;
            if (c == nColors - 1) {
                printSolution();
            } else {
                backtrack(i, c + 1);
            }
        }
    }
}

int main() {
    int i, j, k;
    printf("Enter the number of vertices: ");
    scanf("%d", &nVertices);
    printf("Enter the number of colors: ");
    scanf("%d", &nColors);

    initializeGraph();
    readGraph();

    srand(time(NULL));
    for (i = 0; i < nVertices; i++) {
        color[i] = rand() % nColors;
    }

    backtrack(0, 0);

    return 0;
}
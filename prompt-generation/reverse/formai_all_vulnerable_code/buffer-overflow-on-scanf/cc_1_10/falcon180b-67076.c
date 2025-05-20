//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;
int numColors;
int color[MAX_VERTICES];
int visited[MAX_VERTICES];
int minColor;

void initGraph(int n) {
    numVertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void initColors() {
    numColors = rand() % MAX_COLORS + 1;
    minColor = rand() % numColors;
    for (int i = 0; i < numVertices; i++) {
        color[i] = -1;
    }
}

void colorGraph(int v) {
    visited[v] = 1;
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] == 1 &&!visited[i]) {
            int c = rand() % numColors;
            if (color[i] == -1 || c < color[i]) {
                color[i] = c;
            }
        }
    }
}

void printGraph() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initGraph(n);
    initColors();
    for (int i = 0; i < n; i++) {
        colorGraph(i);
    }
    printf("Minimum color used: %d\n", minColor);
    printGraph();
    return 0;
}
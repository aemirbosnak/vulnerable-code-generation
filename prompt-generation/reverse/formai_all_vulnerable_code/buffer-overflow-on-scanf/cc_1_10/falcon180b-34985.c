//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int n;
int colors[MAX_VERTICES];
int colorCount;

void initGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

int isValid(int vertex, int color) {
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void colorGraph(int vertex, int color) {
    colors[vertex] = color;
    colorCount++;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] &&!colors[i]) {
            int newColor = rand() % MAX_COLORS;
            while (!isValid(i, newColor)) {
                newColor = rand() % MAX_COLORS;
            }
            colorGraph(i, newColor);
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initGraph();
    colorGraph(0, rand() % MAX_COLORS);
    printf("Graph colored with %d colors:\n", colorCount);
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                printf("%d ", colors[i]);
            } else {
                printf("N/A ");
            }
        }
        printf("\n");
    }
    return 0;
}
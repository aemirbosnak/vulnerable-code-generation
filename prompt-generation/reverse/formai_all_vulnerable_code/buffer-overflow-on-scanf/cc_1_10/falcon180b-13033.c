//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9

int graph[V][V];
int color[V];
int n;

void initGraph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
}

void initColor() {
    int i;
    for (i = 0; i < V; i++) {
        color[i] = -1;
    }
}

void printSolution() {
    int i, j;
    printf("Vertex   Color\n");
    for (i = 0; i < V; i++) {
        printf("%d %d\n", i, color[i]);
    }
}

int isSafe(int v, int c, int color[], int graph[V][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

int colorGraph(int v, int color[], int graph[V][V]) {
    int i, c;
    for (c = 0; c < V; c++) {
        if (isSafe(v, c, color, graph)) {
            color[v] = c;
            for (i = 0; i < V; i++) {
                graph[v][i] = 0;
                graph[i][v] = 0;
            }
            if (colorGraph(v + 1, color, graph)) {
                return 1;
            }
            color[v] = -1;
            for (i = 0; i < V; i++) {
                graph[v][i] = graph[i][v] = 1;
            }
        }
    }
    return 0;
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initGraph();
    initColor();
    printf("Enter the edges of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 0) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
    colorGraph(0, color, graph);
    printSolution();
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int numColors;

void init() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
    numColors = 0;
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void colorVertices(int v, int c) {
    color[v] = c;
}

int isSafe(int v, int c, int u, int k) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        if (graph[v][i] && color[i] == c && i!= u) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v, int c, int u, int k) {
    int i;
    if (k == numColors - 1) {
        return;
    }
    for (i = 0; i < MAX_VERTICES; i++) {
        if (graph[v][i] && color[i] == -1 && isSafe(v, c, i, k)) {
            color[i] = c;
            backtrack(i, c + 1, v, k + 1);
        }
    }
}

void colorGraph() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        color[i] = -1;
    }
    numColors = 0;
    for (i = 0; i < MAX_VERTICES; i++) {
        if (color[i] == -1) {
            numColors++;
            backtrack(i, 0, -1, 0);
        }
    }
}

int main() {
    int i, j, n, m;
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init();
    printf("Enter the edges (u v): ");
    while (m--) {
        scanf("%d %d", &i, &j);
        addEdge(i, j);
    }
    colorGraph();
    printf("The minimum number of colors required is %d\n", numColors);
    return 0;
}
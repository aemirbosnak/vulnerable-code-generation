//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

#define MAX_V 100
#define MAX_COL 20

int V, E;
int adjList[MAX_V][MAX_V];
int color[MAX_V];
int numColors = 0;
bool used[MAX_COL];

void getInput() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int u, v;
    printf("Enter the edges:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d%d", &u, &v);
        adjList[u][v] = 1;
        adjList[v][u] = 1;
    }
}

void reset() {
    numColors = 0;
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }
}

void selectColor(int v) {
    for (int c = 0; c < numColors; c++) {
        used[c] = false;
    }
    for (int i = 0; i < V; i++) {
        if (adjList[v][i] && color[i] != -1) {
            used[color[i]] = true;
        }
    }
    for (int c = 0; c < numColors; c++) {
        if (!used[c]) {
            color[v] = c;
            return;
        }
    }
    color[v] = numColors++;
}

void graphColor() {
    for (int v = 0; v < V; v++) {
        selectColor(v);
    }
}

void printSolution() {
    printf("Vertex\tColor\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

int main() {
    getInput();
    reset();
    graphColor();
    printSolution();
    return 0;
}
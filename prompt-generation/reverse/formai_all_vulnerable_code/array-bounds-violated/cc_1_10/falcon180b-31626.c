//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 100
#define INF 999999

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int nVertices;
int nColors;

void readGraph() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &nVertices);
    for (i = 0; i < nVertices; i++) {
        for (j = 0; j < nVertices; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &nColors);
    printf("Enter the edges: ");
    int u, v, w;
    while (scanf("%d %d %d", &u, &v, &w) == 3) {
        graph[u][v] = w;
        graph[v][u] = w;
    }
}

void colorGraph(int start) {
    int i, j, k, min;
    for (k = 0; k < nColors; k++) {
        for (i = 0; i < nVertices; i++) {
            if (color[i] == -1 && graph[start][i]!= INF) {
                color[i] = k;
                break;
            }
        }
    }
    for (i = 0; i < nVertices; i++) {
        if (color[i] == -1) {
            for (j = 0; j < nColors; j++) {
                if (color[j] == -1) {
                    color[i] = j;
                    color[j] = i;
                    break;
                }
            }
        }
    }
    for (i = 0; i < nVertices; i++) {
        for (j = 0; j < nVertices; j++) {
            if (graph[i][j]!= INF && color[i]!= color[j]) {
                colorGraph(j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    readGraph();
    colorGraph(0);
    printf("Vertex\tColor\n");
    for (int i = 0; i < nVertices; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
    return 0;
}
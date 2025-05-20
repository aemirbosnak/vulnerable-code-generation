//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

#define MAX_VERTICES 1000

#define WHITE 0
#define GREY 1
#define BLACK 2

#define NOT_VISITED 0
#define VISITED_GREY 1
#define VISITED_BLACK 2

int numVertices;
int **graph;
int *color;
int *parent;

void setGraph(int v, int **graph) {
    int i, j;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }
}

void printSolution(int v) {
    int i;
    printf("Vertex   Color\n");
    for (i = 0; i < v; i++) {
        printf("%d %d\n", i, color[i]);
    }
}

int dfs(int v, int **graph, int *color, int *parent, int c) {
    int i;
    color[v] = c;
    parent[v] = -1;
    for (i = 0; i < numVertices; i++) {
        if (graph[v][i] == 1) {
            if (color[i] == WHITE) {
                parent[i] = v;
                if (!dfs(i, graph, color, parent, c + 1)) {
                    return 0;
                }
            } else if (color[i]!= c) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int i, j, k;
    int **graph;
    int *color;
    int *parent;
    int numColors;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    setGraph(numVertices, graph);

    printf("Enter the number of edges: ");
    scanf("%d", &numVertices);

    setGraph(numVertices, graph);

    numColors = 0;
    for (i = 0; i < numVertices; i++) {
        if (color[i] == WHITE) {
            if (!dfs(i, graph, color, parent, 1)) {
                printf("Graph is not bipartite\n");
                exit(0);
            }
            numColors++;
        }
    }

    printf("The minimum number of colors needed is %d\n", numColors);

    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 100
#define MAX_COLOR_NUM 10

int vertexNum, edgeNum, colorNum;
int graph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
int color[MAX_VERTEX_NUM];

void initGraph(int vertexNum) {
    int i, j;
    for (i = 0; i < vertexNum; i++) {
        for (j = 0; j < vertexNum; j++) {
            graph[i][j] = 0;
        }
    }
}

bool isSafe(int vertex, int c) {
    int i;
    for (i = 0; i < vertexNum; i++) {
        if (graph[vertex][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int vertex) {
    if (vertex == vertexNum) {
        return true;
    }

    int c;
    for (c = 1; c <= colorNum; c++) {
        if (isSafe(vertex, c)) {
            color[vertex] = c;

            if (graphColoringUtil(vertex + 1)) {
                return true;
            }

            color[vertex] = 0;
        }
    }
    return false;
}

void graphColoring() {
    if (!graphColoringUtil(0)) {
        printf("Solution does not exist\n");
        return;
    }

    int i;
    for (i = 0; i < vertexNum; i++) {
        printf("Vertex %d is colored with color %d\n", i, color[i]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &vertexNum);

    printf("Enter number of edges: ");
    scanf("%d", &edgeNum);

    printf("Enter maximum number of colors: ");
    scanf("%d", &colorNum);

    initGraph(vertexNum);

    int i, u, v;
    for (i = 0; i < edgeNum; i++) {
        printf("\nEnter edge %d:\n", i + 1);
        scanf("%d %d", &u, &v);

        graph[u][v] = graph[v][u] = 1;
    }

    graphColoring();

    return 0;
}
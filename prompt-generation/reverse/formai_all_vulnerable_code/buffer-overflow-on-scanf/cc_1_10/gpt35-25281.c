//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

int graph[MAX_EDGES][2];
int colors[MAX_VERTICES];

int n, m;

void printColors() {
    int i;
    printf("Colors:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int isValidColor(int v, int c) {
    int i;
    for (i = 0; i < m; i++) {
        int a = graph[i][0];
        int b = graph[i][1];
        if (a == v && colors[b] == c) {
            return 0;
        }
        if (b == v && colors[a] == c) {
            return 0;
        }
    }
    return 1;
}

void colorGraph(int v) {
    if (v == n) {
        printColors();
        return;
    }
    int c;
    for (c = 1; c <= 4; c++) {
        if (isValidColor(v, c)) {
            colors[v] = c;
            colorGraph(v + 1);
            colors[v] = 0;
        }
    }
}

int main() {
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);
    printf("Enter the number of edges (max %d): ", MAX_EDGES);
    scanf("%d", &m);
    printf("Enter the edges:\n");
    int i;
    for (i = 0; i < m; i++) {
        scanf("%d%d", &graph[i][0], &graph[i][1]);
    }
    colorGraph(0);
    return 0;
}
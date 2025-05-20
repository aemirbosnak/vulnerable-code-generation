//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int v, int m, int col[]) {
    for (int i = 0; i < v; i++) {
        if (graph[i][v] != -1 && col[i] == col[v])
            return false;
    }
    return true;
}

int greedyColoring(int graph[MAX_VERTICES][MAX_VERTICES], int v) {
    int col[MAX_VERTICES];
    int m = MIN_COLOR;

    for (int i = 0; i < v; i++) {
        bool assigned = false;

        for (int c = MIN_COLOR; c <= MAX_COLOR; c++) {
            if (isSafe(graph, i, m, col)) {
                col[i] = c;
                assigned = true;
                break;
            }
        }

        if (!assigned) {
            m++;
            i--;
        }
    }

    return m;
}

int main() {
    int v, e;
    int graph[MAX_VERTICES][MAX_VERTICES];

    scanf("%d %d", &v, &e);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            graph[i][j] = -1;
        }
    }

    for (int i = 0; i < e; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 0;
    }

    printf("Minimum number of colors: %d\n", greedyColoring(graph, v));

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[MAX][MAX];
int color[MAX];
int n;

void init(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void dfs(int v) {
    color[v] = GRAY;
    for (int u = 0; u < n; u++) {
        if (graph[v][u] == 1 && color[u] == WHITE) {
            dfs(u);
        }
    }
    color[v] = BLACK;
}

void coloring(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE) {
            dfs(i);
            count++;
        }
    }
    printf("Minimum colors required: %d\n", count);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init(n);

    printf("Enter the edges:\n");
    int u, v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }

    coloring(n);

    return 0;
}
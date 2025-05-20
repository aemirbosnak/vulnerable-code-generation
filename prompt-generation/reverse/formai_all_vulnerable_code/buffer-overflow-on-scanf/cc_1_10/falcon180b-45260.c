//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define MAX_VERTEX 100
#define MAX_COLOR 100

int graph[MAX_VERTEX][MAX_VERTEX] = {0};
int n, m, k;
int color[MAX_VERTEX];

int is_valid(int v, int c) {
    for (int u = 0; u < n; u++) {
        if (graph[v][u] && color[u] == c) {
            return false;
        }
    }
    return true;
}

void color_graph(int v, int c) {
    color[v] = c;
    for (int u = 0; u < n; u++) {
        if (graph[v][u]) {
            int nc = (c + 1) % k;
            while (!is_valid(u, nc)) {
                nc = (nc + 1) % k;
            }
            color_graph(u, nc);
        }
    }
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
    color_graph(0, 0);
    printf("Graph colored using %d colors:\n", k);
    print_graph();
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 100

int n, m;
int **graph;
int *color;
int *visited;

void init() {
    n = rand() % MAX_NODES + 1;
    m = rand() % n * (n - 1) / 2 + 1;
    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = rand() % MAX_COLORS + 1;
            }
        }
    }
    color = (int *)malloc(n * sizeof(int));
    visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        color[i] = 0;
        visited[i] = 0;
    }
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0) {
                printf(" ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }
}

void print_color() {
    for (int i = 0; i < n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

void color_graph(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i]!= 0 &&!visited[i]) {
            int c = 1;
            while (c <= MAX_COLORS && color[i] == c) {
                c++;
            }
            color[i] = c;
            color_graph(i);
        }
    }
}

int main() {
    srand(time(NULL));
    init();
    printf("Graph:\n");
    print_graph();
    printf("Colors:\n");
    print_color();
    color_graph(0);
    printf("Colors:\n");
    print_color();
    return 0;
}
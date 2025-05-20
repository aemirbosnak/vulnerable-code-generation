//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 1000
#define INF 1000000

int num_vertices, num_colors, **graph;
int *color;

void init(int n) {
    num_vertices = n;
    num_colors = 0;
    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int v, int c) {
    color[v] = c;
    for (int u = 0; u < num_vertices; u++) {
        if (graph[v][u] == 1 && color[u] == -1) {
            dfs(u, c);
        }
    }
}

void color_graph() {
    for (int i = 0; i < num_vertices; i++) {
        if (color[i] == -1) {
            num_colors++;
            dfs(i, num_colors - 1);
        }
    }
}

void print_solution(int n, int m) {
    printf("Minimum number of colors: %d\n", num_colors);
    printf("Vertex\tColor\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

int main(int argc, char *argv[]) {
    int n, m, u, v;

    scanf("%d %d", &n, &m);
    init(n);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    color_graph();

    print_solution(n, m);

    return 0;
}
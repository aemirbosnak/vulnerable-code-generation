//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int nvertices;
int colors[MAX_VERTICES];
int colorcount;

void init_graph(int n) {
    nvertices = n;
    for (int i = 0; i < nvertices; i++) {
        for (int j = 0; j < nvertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int v, int c) {
    colors[v] = c;
    colorcount++;
    for (int u = 0; u < nvertices; u++) {
        if (graph[v][u] == 1 && colors[u] == WHITE) {
            dfs(u, c);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    int max_colors = 1;
    for (int i = 0; i < nvertices; i++) {
        if (colors[i] == WHITE) {
            colorcount = 0;
            dfs(i, max_colors);
            max_colors++;
        }
    }
    printf("The minimum number of colors needed to color the graph is %d\n", max_colors - 1);
    return 0;
}
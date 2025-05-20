//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 9
#define N 10

int graph[V][V];
int color[V];
int n;

void init() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    for (i = 0; i < V; i++) {
        color[i] = 0;
    }
    n = 0;
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

bool is_safe(int v, int c, int x) {
    int i;
    for (i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    for (i = 0; i < V; i++) {
        if (graph[i][x] && color[i] == c) {
            return false;
        }
    }
    return true;
}

void color_graph(int v, int c) {
    color[v] = c;
    n++;
    int i;
    for (i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == 0) {
            color_graph(i, c + 1);
        }
    }
}

int main() {
    int i, j;
    init();
    int k = 0;
    while (k < N) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        k++;
    }
    int c = 1;
    for (i = 0; i < V; i++) {
        if (color[i] == 0) {
            color_graph(i, c);
        }
    }
    printf("The minimum number of colors required is %d\n", n);
    return 0;
}
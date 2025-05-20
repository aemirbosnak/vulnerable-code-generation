//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_colors;

void init_graph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int is_safe(int v, int c, int k) {
    for (int i = 0; i < k; i++) {
        if (colors[i] == c || graph[i][v] == 1) {
            return 0;
        }
    }
    return 1;
}

void color(int v, int k) {
    colors[v] = k;
    for (int i = 0; i < k; i++) {
        if (colors[i] == 0) {
            colors[i] = k;
            break;
        }
    }
    num_colors++;
}

int main() {
    int n, m;
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &n, &m);
    init_graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter the vertices of edge %d: ", i);
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            color(i, k++);
        }
    }
    printf("The chromatic number of the graph is %d\n", num_colors);
    return 0;
}
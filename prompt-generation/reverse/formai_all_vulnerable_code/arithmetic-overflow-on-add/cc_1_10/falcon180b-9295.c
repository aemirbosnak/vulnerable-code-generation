//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 7

int graph[MAX_NODES][MAX_NODES];
int n;
int m;
int colors[MAX_NODES];
int color_count;

void init_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int dfs_color(int node, int color) {
    int i;
    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    colors[node] = color;
    return 1;
}

int greedy_color() {
    int i, j;
    for (i = 0; i < n; i++) {
        colors[i] = -1;
    }
    color_count = 0;
    for (i = 0; i < n; i++) {
        if (colors[i] == -1) {
            int color = 0;
            while (color < MAX_COLORS) {
                int flag = 1;
                for (j = 0; j < n; j++) {
                    if (graph[i][j] == 1 && colors[j] == color) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    colors[i] = color;
                    color_count++;
                    break;
                }
                color++;
            }
        }
    }
    return color_count;
}

int main() {
    int i, j;
    srand(time(NULL));
    n = rand() % MAX_NODES + 1;
    m = rand() % (n * (n - 1) / 2) + 1;
    printf("Number of nodes: %d\n", n);
    printf("Number of edges: %d\n", m);
    init_graph();
    for (i = 0; i < m; i++) {
        int u, v;
        do {
            u = rand() % n;
            v = rand() % n;
        } while (u == v);
        add_edge(u, v);
    }
    int result_dfs = dfs_color(0, 0);
    int result_greedy = greedy_color();
    printf("DFS coloring: %d colors\n", result_dfs);
    printf("Greedy coloring: %d colors\n", result_greedy);
    return 0;
}
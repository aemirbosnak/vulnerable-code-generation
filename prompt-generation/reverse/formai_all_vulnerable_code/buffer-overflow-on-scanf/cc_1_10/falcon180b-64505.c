//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

int N, M;
int graph[MAX_NODES][MAX_EDGES];
int color[MAX_NODES];

void init() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_EDGES; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int dfs(int u, int c) {
    color[u] = c;
    for (int v = 0; v < N; v++) {
        if (graph[u][v] == 1 && color[v] == 0) {
            int k = 1;
            while (color[k] == 1) {
                k++;
            }
            if (k > c) {
                c = k;
            }
        }
    }
    return c;
}

int main() {
    scanf("%d %d", &N, &M);
    init();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i!= j) {
                add_edge(i, j);
            }
        }
    }
    int max_color = 0;
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            int c = dfs(i, 1);
            if (c > max_color) {
                max_color = c;
            }
        }
    }
    printf("%d\n", max_color);
    return 0;
}
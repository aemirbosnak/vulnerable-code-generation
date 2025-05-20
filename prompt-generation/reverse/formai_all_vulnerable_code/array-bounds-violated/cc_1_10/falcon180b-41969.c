//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 1000

int N, M, K;
int degree[MAXN];
int color[MAXN];
int V[MAXN];
int E[MAXN];

void init() {
    memset(degree, 0, sizeof(degree));
    memset(color, -1, sizeof(color));
    memset(V, 0, sizeof(V));
    memset(E, 0, sizeof(E));
}

void add_edge(int u, int v) {
    E[M++] = u;
    E[M++] = v;
    degree[u]++;
    degree[v]++;
}

int dfs(int u) {
    int c = 1;
    for (int i = 0; i < K; i++) {
        if (color[u] == i) {
            c = i;
            break;
        }
    }
    for (int v = 0; v < N; v++) {
        if (E[v] == u) {
            int nc = dfs(v);
            if (nc == -1) {
                return -1;
            }
            if (nc == c) {
                return -1;
            }
        }
    }
    return c;
}

int graph_coloring() {
    int c = 1;
    for (int i = 0; i < N; i++) {
        if (color[i] == -1) {
            color[i] = c;
            if (dfs(i) == -1) {
                return -1;
            }
            c++;
        }
    }
    return c;
}

void print_solution() {
    printf("Vertex\tColor\n");
    for (int i = 0; i < N; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    init();
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    int res = graph_coloring();
    if (res == -1) {
        printf("No solution\n");
    } else {
        printf("Chromatic number: %d\n", res);
        print_solution();
    }
    return 0;
}
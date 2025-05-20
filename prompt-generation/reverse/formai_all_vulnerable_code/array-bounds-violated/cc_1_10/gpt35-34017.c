//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int N, M, K;
int G[MAX_N][MAX_N];
int colors[MAX_N];

int is_feasible(int v, int c) {
    for (int i = 0; i < N; i++) {
        if (G[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int v) {
    if (v == N) {
        return 1;
    }
    for (int c = 1; c <= K; c++) {
        if (is_feasible(v, c)) {
            colors[v] = c;
            if (graph_coloring(v+1)) {
                return 1;
            }
            colors[v] = 0;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    if (graph_coloring(0)) {
        printf("Possible coloring:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    } else {
        printf("No coloring possible\n");
    }
    return 0;
}
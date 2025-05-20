//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100 // Maximum number of vertices
#define MAXC 5 // Maximum number of colors

int N, M; // Number of vertices and edges
int adj[MAXN][MAXN]; // Adjacency matrix
int color[MAXN]; // Color of each vertex
int used[MAXC]; // Used colors array

int get_best_color(int v) {
    int i, j, k, mx = 0, best = 0;
    for (i = 1; i <= MAXC; i++) {
        if (!used[i]) {
            int cnt = 0;
            for (j = 0; j < N; j++) {
                if (adj[v][j] && color[j] == i) {
                    cnt++;
                }
            }
            if (cnt > mx) {
                mx = cnt;
                best = i;
            }
        }
    }
    return best;
}

int can_color(int v, int c) {
    int i;
    for (i = 0; i < N; i++) {
        if (adj[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

int color_graph(int v) {
    int i, j, k;
    if (v == N) {
        return 1;
    }
    for (i = 1; i <= MAXC; i++) {
        if (can_color(v, i)) {
            used[i] = 1;
            color[v] = i;
            if (color_graph(v + 1)) {
                return 1;
            }
            color[v] = 0;
            used[i] = 0;
        }
    }
    return 0;
}

int main() {
    int i, j, k;
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    if (color_graph(0)) {
        printf("Graph can be colored with %d colors:\n", MAXC);
        for (i = 0; i < N; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
    } else {
        printf("Graph cannot be colored with %d colors.\n", MAXC);
    }
    return 0;
}
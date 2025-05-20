//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int n;
    int m;
    int** adj;
} graph_t;

graph_t* create_graph(int n, int m) {
    graph_t* g = malloc(sizeof(graph_t));
    g->n = n;
    g->m = m;
    g->adj = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        g->adj[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

void destroy_graph(graph_t* g) {
    for (int i = 0; i < g->n; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

int is_safe(graph_t* g, int v, int c) {
    for (int i = 0; i < g->n; i++) {
        if (g->adj[v][i] == 1 && g->adj[i][c] == 1) {
            return 0;
        }
    }
    return 1;
}

int graph_color(graph_t* g, int v, int* colors) {
    if (v == g->n) {
        return 1;
    }
    for (int c = 1; c <= g->n; c++) {
        if (is_safe(g, v, c)) {
            colors[v] = c;
            if (graph_color(g, v + 1, colors)) {
                return 1;
            }
            colors[v] = 0;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    graph_t* g = create_graph(n, m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g->adj[u - 1][v - 1] = 1;
        g->adj[v - 1][u - 1] = 1;
    }
    int* colors = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }
    if (graph_color(g, 0, colors)) {
        for (int i = 0; i < n; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    } else {
        printf("No solution\n");
    }
    destroy_graph(g);
    free(colors);
    return 0;
}
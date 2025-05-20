//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n;
    int **adj;
} graph;

int **alloc_matrix(int n)
{
    int **m = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m[i] = malloc(n * sizeof(int));
    }
    return m;
}

void free_matrix(int **m, int n)
{
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

graph *read_graph()
{
    int n, m;
    scanf("%d %d", &n, &m);
    graph *g = malloc(sizeof(graph));
    g->n = n;
    g->adj = alloc_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g->adj[u - 1][v - 1] = 1;
        g->adj[v - 1][u - 1] = 1;
    }
    return g;
}

void print_graph(graph *g)
{
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int *greedy_coloring(graph *g)
{
    int *color = malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++) {
        color[i] = -1;
    }
    for (int i = 0; i < g->n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            for (int j = 0; j < g->n; j++) {
                if (g->adj[i][j] && color[j] == 0) {
                    color[j] = 1;
                }
            }
        }
    }
    return color;
}

void print_coloring(int *color, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int main()
{
    graph *g = read_graph();
    int *color = greedy_coloring(g);
    print_coloring(color, g->n);
    free_matrix(g->adj, g->n);
    free(g);
    free(color);
    return 0;
}
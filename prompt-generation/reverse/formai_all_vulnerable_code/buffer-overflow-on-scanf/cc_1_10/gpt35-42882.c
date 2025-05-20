//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int n;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph* g, int n) {
    int i, j;
    g->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            g->adj_matrix[i][j] = 0;
}

void add_edge(Graph* g, int x, int y) {
    g->adj_matrix[x][y] = 1;
    g->adj_matrix[y][x] = 1;
}

int is_valid(Graph* g, int v, int c, int color[]) {
    int i;
    for (i = 1; i <= g->n; i++)
        if (g->adj_matrix[v][i] && color[i] == c)
            return 0;
    return 1;
}

int graph_coloring(Graph* g, int m, int v, int color[]) {
    int c, i;
    if (v == g->n + 1)
        return 1;
    for (c = 1; c <= m; c++) {
        if (is_valid(g, v, c, color)) {
            color[v] = c;
            if (graph_coloring(g, m, v + 1, color))
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    int n, m, i, j, x, y;
    Graph g;
    int color[MAX_VERTICES];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph(&g, n);
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    for (i = 1; i <= n; i++) {
        printf("Enter the edges for vertex %d (-1 to stop): ", i);
        scanf("%d", &x);
        while (x != -1) {
            add_edge(&g, i, x);
            scanf("%d", &x);
        }
    }
    for (i = 1; i <= n; i++)
        color[i] = 0;
    if (graph_coloring(&g, m, 1, color)) {
        printf("The vertices can be colored using %d colors as:\n", m);
        for (i = 1; i <= n; i++)
            printf("Vertex %d: Color %d\n", i, color[i]);
    } else {
        printf("The vertices cannot be colored using %d colors.\n", m);
    }
    return 0;
}
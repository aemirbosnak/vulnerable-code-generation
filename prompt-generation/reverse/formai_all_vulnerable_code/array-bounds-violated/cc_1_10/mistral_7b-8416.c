//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 500000

typedef struct {
    int adj_list[MAX_VERTICES];
    bool visited;
} graph;

graph g[MAX_VERTICES];
int color[MAX_VERTICES];
int num_colors = 0;

bool dfs(int v) {
    if (g[v].visited)
        return false;

    g[v].visited = true;

    for (int i = 0; i < MAX_VERTICES; i++) {
        int w = g[v].adj_list[i];
        if (w >= 0 && color[w] == color[v] && dfs(w)) {
            return false;
        }
    }

    color[v] = num_colors++;
    return true;
}

void add_edge(int u, int v) {
    g[u].adj_list[g[u].adj_list[MAX_VERTICES]++] = v;
    g[v].adj_list[g[v].adj_list[MAX_VERTICES]++] = u;
}

bool graph_coloring(int n, int m) {
    for (int i = 0; i <= n; i++) {
        g[i].visited = false;
        color[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfs(i))
            return false;
    }

    return true;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    if (graph_coloring(n, m)) {
        printf("Graph %d can be colored with %d colors.\n", n, num_colors);
        for (int i = 1; i <= n; i++)
            printf("Vertex %d has color %d.\n", i, color[i]);
    } else {
        printf("Graph %d cannot be colored.\n", n);
    }

    return 0;
}
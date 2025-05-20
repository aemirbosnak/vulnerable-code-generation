//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
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

void init_colors() {
    int i;
    for (i = 0; i < n; i++) {
        colors[i] = 0;
    }
}

int dfs(int node, int color) {
    int i;
    colors[node] = color;
    color_count++;

    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && colors[i] == 0) {
            if (dfs(i, (color + 1) % MAX_COLORS) == 0) {
                return 0;
            }
        } else if (graph[node][i] == 1 && colors[i]!= (color + 1) % MAX_COLORS) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int i, j;
    srand(time(NULL));

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    init_graph();

    printf("Enter the edges:\n");
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    init_colors();

    if (dfs(0, 0) == 0) {
        printf("Graph cannot be colored with %d colors.\n", MAX_COLORS);
    } else {
        printf("Graph colored with %d colors.\n", color_count);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 1000

typedef struct {
    int node;
    int color;
} Edge;

int graph[MAX_NODES][MAX_NODES];
int color_count[MAX_COLORS];

void init_graph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int n, int i, int j) {
    graph[i][j] = 1;
    graph[j][i] = 1;
}

int dfs(int n, int node, int color, int k) {
    color_count[color]++;
    if (k == n) {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && color_count[i] == 0) {
            color_count[i] = 1;
            count += dfs(n, i, color + 1, k + 1);
        }
    }

    return count;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    init_graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(n, u, v);
    }

    int max_color = 0;
    for (int i = 0; i < n; i++) {
        int color = 0;
        int count = dfs(n, i, color, 0);
        if (count == n) {
            max_color = color;
        }
    }

    printf("Max color: %d\n", max_color);

    return 0;
}
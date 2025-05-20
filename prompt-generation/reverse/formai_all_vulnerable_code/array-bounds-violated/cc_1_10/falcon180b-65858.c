//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[MAX_NODES][MAX_NODES];
int n, m;

void dfs(int node, int color[], int parent) {
    color[node] = GRAY;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && i!= parent) {
            dfs(i, color, node);
        }
    }
    color[node] = BLACK;
}

int main() {
    scanf("%d %d", &n, &m);

    int color[MAX_NODES];
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE) {
            dfs(i, color, -1);
        }
    }

    int num_colors = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE) {
            color[i] = BLACK;
            num_colors++;
        }
    }

    printf("The minimum number of colors needed to color the graph is %d\n", num_colors);

    return 0;
}
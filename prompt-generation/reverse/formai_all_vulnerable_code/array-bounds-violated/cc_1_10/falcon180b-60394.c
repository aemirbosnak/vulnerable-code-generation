//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 1000
#define MAX_EDGES 10000
#define INF 999999

int n, m;
int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
int color_count;
int visited[MAX_NODES];

void initialize() {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        colors[i] = rand() % MAX_COLORS;
    }
    color_count = MAX_COLORS;
}

void visit(int node) {
    visited[node] = 1;
    for (int i = 0; i < n; ++i) {
        if (graph[node][i]!= 0) {
            if (!visited[i]) {
                visit(i);
            }
        }
    }
}

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < n; ++i) {
        if (graph[node][i]!= 0) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }
}

void color_node(int node, int color) {
    colors[node] = color;
    color_count--;
}

void color(int node) {
    int color = rand() % color_count;
    while (colors[node] == color) {
        color = rand() % color_count;
    }
    color_node(node, color);
}

int main() {
    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &n, &m);
    initialize();

    int u, v;
    printf("Enter the edges: ");
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        --u;
        --v;
        graph[u][v] = graph[v][u] = 1;
    }

    int start_node = rand() % n;
    color(start_node);
    dfs(start_node);

    printf("The graph is colored with %d colors:\n", color_count);
    for (int i = 0; i < n; ++i) {
        printf("%d: %d\n", i, colors[i]);
    }

    return 0;
}
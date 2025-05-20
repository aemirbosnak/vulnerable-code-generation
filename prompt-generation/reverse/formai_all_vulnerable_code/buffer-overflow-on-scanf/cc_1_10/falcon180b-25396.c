//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[MAX_NODES][MAX_EDGES];
int color[MAX_NODES];
int n, m;

void init() {
    srand(time(NULL));
    m = rand() % MAX_EDGES + 1;
    printf("Enter the number of nodes (max %d): ", MAX_NODES - 1);
    scanf("%d", &n);
    printf("Enter the number of edges (max %d): ", MAX_EDGES - 1);
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_EDGES; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][color[u]++] = v;
    graph[v][color[v]++] = u;
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < color[i]; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void color_graph(int u) {
    color[u] = WHITE;
    for (int v = 0; v < n; v++) {
        if (graph[u][v]!= 0) {
            graph[u][v] = -graph[u][v];
            graph[v][graph[u][v]] = -graph[u][v];
        }
    }
    for (int v = 0; v < n; v++) {
        if (graph[u][v]!= 0) {
            color_graph(v);
        }
    }
}

int main() {
    init();
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter the nodes for edge %d: ", i);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    int start_node = rand() % n;
    printf("Coloring the graph...\n");
    color_graph(start_node);
    printf("Colored graph:\n");
    print_graph();
    return 0;
}
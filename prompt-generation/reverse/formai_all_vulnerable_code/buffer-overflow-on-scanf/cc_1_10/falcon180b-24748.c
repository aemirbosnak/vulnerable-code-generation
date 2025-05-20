//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

int graph[MAX_NODES][MAX_EDGES];
int n, m;
int colors[MAX_NODES];
int color_count;

void init_graph() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_EDGES; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][color_count] = v;
    graph[v][color_count] = u;
    color_count++;
}

int dfs(int u, int c) {
    colors[u] = c;
    for (int i = 0; i < MAX_EDGES; i++) {
        int v = graph[u][i];
        if (v!= 0 && colors[v] == 0) {
            int x = dfs(v, c + 1);
            if (x == 0) {
                return 0;
            }
        } else if (colors[v]!= c && colors[v]!= 0) {
            return 0;
        }
    }
    return 1;
}

int color_graph() {
    srand(time(NULL));
    for (int i = 0; i < MAX_NODES; i++) {
        colors[i] = 0;
    }
    for (int i = 0; i < MAX_NODES; i++) {
        if (colors[i] == 0) {
            int c = rand() % 7 + 1;
            if (dfs(i, c) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init_graph();
    for (i = 0; i < m; i++) {
        int u, v;
        printf("Enter the nodes for edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    if (color_graph() == 0) {
        printf("Graph cannot be colored.\n");
    } else {
        printf("Graph colored successfully.\n");
    }
    return 0;
}
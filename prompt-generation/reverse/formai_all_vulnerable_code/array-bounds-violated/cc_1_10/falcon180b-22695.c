//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_V 100
#define MAX_E 1000
#define MAX_COLOR 100
#define INF INT_MAX

int V, E;
int adj[MAX_V][MAX_V];
int color[MAX_V];
int parent[MAX_V];
int color_cnt;

void init() {
    for (int i = 0; i < V; i++) {
        color[i] = -1;
        parent[i] = -1;
    }
    color_cnt = 0;
}

void read_graph() {
    int u, v;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        printf("Enter the edges (u, v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
}

void dfs_color(int v) {
    int c = ++color_cnt;
    color[v] = c;
    for (int u = 0; u < V; u++) {
        if (adj[v][u] && color[u] == -1) {
            parent[u] = v;
            dfs_color(u);
        } else if (adj[v][u] && color[u]!= -1 && color[u]!= c) {
            printf("Graph is not proper!\n");
            exit(0);
        }
    }
}

int main() {
    srand(time(NULL));
    init();
    read_graph();
    dfs_color(0);
    printf("Vertex\tColor\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
    return 0;
}
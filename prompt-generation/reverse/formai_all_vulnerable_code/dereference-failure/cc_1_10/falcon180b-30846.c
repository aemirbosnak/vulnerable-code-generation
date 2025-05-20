//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF INT_MAX

typedef struct {
    int from, to, color;
} Edge;

Edge edges[MAX_EDGES];
int n_edges;

int n_nodes;
int *colors;

void init_graph(int n) {
    srand(time(NULL));
    n_nodes = n;
    n_edges = 0;
    int i;
    for (i = 0; i < n_nodes; i++) {
        colors[i] = rand() % 6 + 1;
    }
}

void add_edge(int from, int to) {
    Edge *e = &edges[n_edges++];
    e->from = from;
    e->to = to;
    e->color = -1;
}

int dfs(int node, int color) {
    colors[node] = color;
    int max_color = 0;
    int i;
    for (i = 0; i < n_edges; i++) {
        Edge *e = &edges[i];
        if (e->from == node && e->color == -1) {
            int new_color = (color + 1) % 6;
            if (new_color > max_color) {
                max_color = new_color;
            }
            e->color = new_color;
        } else if (e->to == node && e->color == -1) {
            int new_color = (color + 5) % 6;
            if (new_color > max_color) {
                max_color = new_color;
            }
            e->color = new_color;
        }
    }
    return max_color;
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    init_graph(n);
    int i;
    for (i = 0; i < n_nodes; i++) {
        int color = dfs(i, colors[i]);
        printf("%d ", color);
    }
    printf("\n");
    return 0;
}
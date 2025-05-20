//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define MAX_EDGES 20
#define MAX_COLOR 6

int graph[MAX_NODES][MAX_NODES];
int n, m;
int colors[MAX_NODES];

bool is_valid_color(int node, int color) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

void color_graph() {
    for (int i = 0; i < n; i++) {
        colors[i] = 1;
    }

    int node = 0;
    while (node < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && colors[i] == 0) {
                colors[i] = colors[node] + 1;
                found = true;
                break;
            }
        }
        if (!found) {
            node++;
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    color_graph();

    printf("The graph is colored with %d colors.\n", colors[0]);

    return 0;
}
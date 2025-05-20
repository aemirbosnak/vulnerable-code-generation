//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

int color[MAX_NODES];
int adj[MAX_NODES][MAX_NODES];
int num_nodes;

bool is_safe(int node, int c) {
    for (int i = 0; i < num_nodes; i++) {
        if (adj[node][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graph_color(int node) {
    if (node == num_nodes) {
        return true;
    }

    for (int i = 1; i <= num_nodes; i++) {
        if (is_safe(node, i)) {
            color[node] = i;

            if (graph_color(node + 1)) {
                return true;
            }

            color[node] = 0;
        }
    }

    return false;
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (graph_color(0)) {
        printf("Possible coloring:\n");
        for (int i = 0; i < num_nodes; i++) {
            printf("Node %d: %d\n", i + 1, color[i]);
        }
    } else {
        printf("No valid coloring.\n");
    }

    return 0;
}
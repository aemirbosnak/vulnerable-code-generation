//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 50

int nodes, edges;
int adjacency_matrix[MAX_NODES][MAX_NODES] = {{0}};
int node_colors[MAX_NODES] = {0};

bool is_valid_color(int node, int color) {
    for (int i = 0; i < nodes; i++) {
        if (adjacency_matrix[node][i] && color == node_colors[i]) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int node) {
    if (node == nodes) {
        return true;
    }

    for (int color = 1; color <= nodes; color++) {
        if (is_valid_color(node, color)) {
            node_colors[node] = color;
            if (graph_coloring(node + 1)) {
                return true;
            }
            node_colors[node] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int from, to;
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &from, &to);
        adjacency_matrix[from][to] = adjacency_matrix[to][from] = 1;
    }

    if (graph_coloring(0)) {
        printf("The graph can be colored with the following colors:\n");
        for (int i = 0; i < nodes; i++) {
            printf("Node %d: Color %d\n", i+1, node_colors[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors.\n", nodes);
    }
    return 0;
}
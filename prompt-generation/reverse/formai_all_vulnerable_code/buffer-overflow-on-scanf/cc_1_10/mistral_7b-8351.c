//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MIN_COLOR 1
#define MAX_COLOR 6

typedef struct {
    int node;
    int color;
} Node;

bool graph[MAX_NODES][MAX_NODES];
Node nodes[MAX_NODES];

int coloring(int node, int current_color) {
    if (node >= MAX_NODES) {
        return true;
    }

    if (nodes[node].color != -1) {
        return nodes[node].color == current_color;
    }

    for (int neighbor = 0; neighbor < MAX_NODES; neighbor++) {
        if (graph[node][neighbor] && coloring(neighbor, current_color)) {
            nodes[node].color = current_color;
            return true;
        }
    }

    for (int color = MIN_COLOR; color <= MAX_COLOR; color++) {
        if (!coloring(node, color)) {
            nodes[node].color = color;
            return true;
        }
    }

    return false;
}

int main() {
    int num_nodes, num_edges;

    scanf("%d%d", &num_nodes, &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d%d", &node1, &node2);
        graph[node1][node2] = true;
        graph[node2][node1] = true;
    }

    for (int i = 0; i < num_nodes; i++) {
        nodes[i].color = -1;
    }

    coloring(0, MIN_COLOR);

    for (int i = 0; i < num_nodes; i++) {
        printf("Settlement %d has color %d\n", i, nodes[i].color);
    }

    return 0;
}
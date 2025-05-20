//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 20

int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];

bool isSafe(int node, int color, int nodes) {
    for (int i = 0; i < nodes; i++) {
        if (graph[node][i] && color == colors[i])
            return false;
    }

    return true;
}

bool colorGraph(int node, int total_nodes, int total_colors) {
    if (node == total_nodes)
        return true;

    for (int i = 1; i <= total_colors; i++) {
        if (isSafe(node, i, total_nodes)) {
            colors[node] = i;

            if (colorGraph(node + 1, total_nodes, total_colors))
                return true;

            colors[node] = 0;
        }
    }

    return false;
}

int main() {
    int total_nodes, total_edges, u, v, total_colors;

    printf("Enter Total Nodes: ");
    scanf("%d", &total_nodes);

    printf("Enter Total Edges: ");
    scanf("%d", &total_edges);

    printf("Enter Total Colors: ");
    scanf("%d", &total_colors);

    for (int i = 0; i < total_edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // Direct Edge
        graph[u][v] = 1;
        // Undirected Edge
        // graph[u][v] = graph[v][u] = 1;
    }

    if (colorGraph(0, total_nodes, total_colors)) {
        printf("Nodes can be colored with %d colors as follows:\n", total_colors);

        for (int i = 0; i < total_nodes; i++) {
            printf("Node %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("The given graph cannot be colored with %d colors\n", total_colors);
    }

    return 0;
}
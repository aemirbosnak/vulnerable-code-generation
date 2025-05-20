//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10    // Maximum number of nodes
#define COLORS 3  // Number of colors available

int adj[MAX][MAX];  // Adjacency matrix
int color[MAX];     // Array to hold color of each node

// Function to check if we can color the current node with given "c" color
int validColor(int node, int c, int nodes) {
    for (int i = 0; i < nodes; i++) {
        if (adj[node][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Function to color the nodes using the given "colors" array
int colorGraph(int node, int nodes, int colors[]) {
    if (node == nodes) {
        return 1;  // All nodes are colored
    }

    for (int i = 0; i < COLORS; i++) {
        if (validColor(node, colors[i], nodes)) {
            color[node] = colors[i];  // Set color for current node

            if (colorGraph(node + 1, nodes, colors)) {
                return 1;  // Solution found
            }

            color[node] = 0;  // Backtrack
        }
    }

    return 0;  // Solution not found
}

int main() {
    int nodes, edges;
    int node1, node2;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge #%d: ", i + 1);
        scanf("%d %d", &node1, &node2);
        adj[node1][node2] = adj[node2][node1] = 1;
    }

    // Available colors
    int colors[COLORS] = {1, 2, 3};

    // Color the graph
    if (colorGraph(0, nodes, colors)) {
        printf("The graph can be colored using %d colors.\n", COLORS);
        printf("Colors of the nodes are:\n");
        for (int i = 0; i < nodes; i++) {
            printf("Node %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("The graph cannot be colored using %d colors.\n", COLORS);
    }

    return 0;
}
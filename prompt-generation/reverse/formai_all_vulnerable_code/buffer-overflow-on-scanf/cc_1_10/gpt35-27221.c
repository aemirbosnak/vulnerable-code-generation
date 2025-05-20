//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int graph[MAX_NODES][MAX_NODES]; // adjacency matrix representing the graph
int color[MAX_NODES]; // color of each node
bool used_colors[MAX_COLORS]; // array keeping track of used colors
int num_nodes, num_edges; // number of nodes and edges in the graph

bool is_safe(int node, int c) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int node) {
    if (node == num_nodes) { // all nodes have been colored
        return true;
    }
    for (int i = 0; i < MAX_COLORS; i++) { // try all possible colors for this node
        if (is_safe(node, i) && !used_colors[i]) {
            color[node] = i;
            used_colors[i] = true;
            if (graph_coloring(node + 1)) {
                return true;
            }
            used_colors[i] = false; // backtrack
            color[node] = -1; // unset color
        }
    }
    return false;
}

int main() {
    // read input
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &num_nodes, &num_edges);
    printf("Enter the edges:\n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // graph is undirected
    }

    // initialization of color and used_colors arrays
    for (int i = 0; i < num_nodes; i++) {
        color[i] = -1; // no color has been assigned yet
    }
    for (int i = 0; i < MAX_COLORS; i++) {
        used_colors[i] = false; // no colors have been used yet
    }

    // attempt to color the graph
    if (graph_coloring(0)) {
        printf("The graph can be colored as follows:\n");
        for (int i = 0; i < num_nodes; i++) {
            printf("Node %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("The graph cannot be colored with %d or less colors.\n", MAX_COLORS);
    }

    return 0;
}
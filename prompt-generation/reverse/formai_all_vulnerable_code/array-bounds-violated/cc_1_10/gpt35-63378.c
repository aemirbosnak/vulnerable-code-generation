//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50
#define MAX_COLOR_OPTIONS 5

int nodes, edges, colors;
int graph[MAX_NODES][MAX_NODES];
int node_colors[MAX_NODES];

void print_solution(int node_colors[]) {
    printf("The minimum colors required to color the graph is %d. The following is a possible coloring:\n", colors);
    for (int i=0; i<nodes; i++) {
        printf("Node %d -> Color %d\n", i+1, node_colors[i]);
    }
}

int is_safe(int node, int color, int node_colors[]) {
    for (int i=0; i<nodes; i++) {
        if (graph[node][i] && color == node_colors[i]) {
            return 0;
        }
    }
    return 1;
}

int color_graph(int node, int node_colors[]) {
    if (node == nodes) {
        return 1;
    }

    for (int i=1; i<=colors; i++) {
        if (is_safe(node, i, node_colors)) {
            node_colors[node] = i;

            if (color_graph(node+1, node_colors)) {
                return 1;
            }

            node_colors[node] = 0;
        }
    }

    return 0;
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the maximum number of colors allowed: ");
    scanf("%d", &colors);

    printf("Enter the edges of the graph (node 1 to node 2):\n");

    for (int i=0; i<edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);

        graph[node1-1][node2-1] = 1;
        graph[node2-1][node1-1] = 1;
    }

    if (color_graph(0, node_colors)) {
        print_solution(node_colors);
    }
    else {
        printf("Couldn't find a valid coloring with %d colors or less.\n", colors);
    }

    return 0;
}
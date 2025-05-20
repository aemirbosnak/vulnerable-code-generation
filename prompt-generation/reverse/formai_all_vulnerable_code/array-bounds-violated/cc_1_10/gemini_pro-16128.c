//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct {
    int num_nodes;
    int num_edges;
    int graph[MAX_NODES][MAX_NODES];
} Graph;

Graph create_graph(int num_nodes, int num_edges) {
    Graph graph = {num_nodes, num_edges, {{0}}};

    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph.graph[node1][node2] = 1;
        graph.graph[node2][node1] = 1;
    }

    return graph;
}

bool is_safe(Graph graph, int node, int color, int *colors) {
    for (int i = 0; i < graph.num_nodes; i++) {
        if (graph.graph[node][i] && colors[i] == color) {
            return false;
        }
    }

    return true;
}

bool graph_color(Graph graph, int node, int *colors, int num_colors) {
    if (node == graph.num_nodes) {
        return true;
    }

    for (int color = 1; color <= num_colors; color++) {
        if (is_safe(graph, node, color, colors)) {
            colors[node] = color;
            if (graph_color(graph, node + 1, colors, num_colors)) {
                return true;
            }
            colors[node] = 0;
        }
    }

    return false;
}

void print_colors(int *colors, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", colors[i]);
    }

    printf("\n");
}

int main() {
    int num_nodes, num_edges, num_colors;
    scanf("%d %d %d", &num_nodes, &num_edges, &num_colors);

    Graph graph = create_graph(num_nodes, num_edges);

    int colors[MAX_NODES] = {0};

    if (graph_color(graph, 0, colors, num_colors)) {
        print_colors(colors, num_nodes);
    } else {
        printf("No solution\n");
    }

    return 0;
}
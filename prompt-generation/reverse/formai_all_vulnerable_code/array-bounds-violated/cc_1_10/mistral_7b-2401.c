//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int vertex;
    int color;
} Node;

#define MAX_VERTEX 50
#define MAX_EDGE 100

int graph[MAX_VERTEX][MAX_VERTEX];
Node nodes[MAX_VERTEX];
int num_nodes, num_edges, curr_color = 0;

void add_edge(int a, int b) {
    graph[a][num_edges] = b;
    graph[b][num_edges] = a;
    num_edges++;
}

int is_safe(int node, int color) {
    for (int i = 0; i < num_edges; i++) {
        if (graph[node][i] != -1 && nodes[graph[node][i]].color == color) {
            return 0;
        }
    }
    return 1;
}

void graph_coloring_helper(int node) {
    if (node >= num_nodes) {
        printf("\nSolution:\n");
        for (int i = 0; i < num_nodes; i++) {
            printf("%d -> %d\n", i, nodes[i].color);
        }
        return;
    }

    for (int color = 0; color < 6; color++) {
        if (is_safe(node, color)) {
            nodes[node].color = color;
            graph_coloring_helper(node + 1);
        }
    }

    nodes[node].color = -1; // Backtracking
}

int main() {
    int test_case;
    scanf("%d", &test_case);

    for (int i = 0; i < test_case; i++) {
        scanf("%d %d", &num_nodes, &num_edges);

        memset(nodes, -1, sizeof(Node) * num_nodes);

        for (int j = 0; j < num_edges; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            add_edge(a, b);
        }

        graph_coloring_helper(0);

        if (nodes[num_nodes - 1].color == -1) {
            printf("No solution exists for this graph.\n");
        }
    }

    return 0;
}
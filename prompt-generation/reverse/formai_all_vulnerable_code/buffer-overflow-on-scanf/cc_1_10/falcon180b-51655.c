//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 7
#define INF 9999

int num_nodes, num_colors;
int graph[MAX_NODES][MAX_NODES];
int color_map[MAX_NODES];

void read_graph(void) {
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the neighbors of node %d (separated by spaces): ", i);
        int neighbors[MAX_NODES];
        int num_neighbors = 0;
        while (scanf("%d", &neighbors[num_neighbors])!= EOF) {
            graph[i][num_neighbors] = neighbors[num_neighbors];
            graph[neighbors[num_neighbors]][i] = i;
            num_neighbors++;
        }
    }
}

bool is_safe(int node, int color, int prev_node) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i]!= INF && color_map[i] == color && i!= prev_node) {
            return false;
        }
    }
    return true;
}

void color_graph(int node, int color) {
    color_map[node] = color;

    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i]!= INF && color_map[i] == -1) {
            for (int j = 1; j <= num_colors; j++) {
                if (is_safe(i, j, node)) {
                    color_map[i] = j;
                    color_graph(i, j);
                    break;
                }
            }
        }
    }
}

int main(void) {
    read_graph();
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    for (int i = 0; i < num_nodes; i++) {
        if (color_map[i] == -1) {
            color_graph(i, 1);
        }
    }

    printf("The graph is colored with %d colors:\n", num_colors);
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", color_map[i]);
    }
    printf("\n");

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_COLORS 10

int num_nodes, num_colors;
int *graph;
int *colors;

bool is_valid(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node * num_nodes + i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

void backtrack(int node, int color) {
    if (node == num_nodes) {
        printf("Solution found!\n");
        for (int i = 0; i < num_nodes; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= num_colors; i++) {
            if (is_valid(node, i)) {
                colors[node] = i;
                backtrack(node + 1, i);
            }
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter number of colors: ");
    scanf("%d", &num_colors);

    graph = (int *)malloc(num_nodes * num_nodes * sizeof(int));
    colors = (int *)malloc(num_nodes * sizeof(int));

    printf("Enter graph adjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i * num_nodes + j]);
        }
    }

    backtrack(0, 1);

    return 0;
}
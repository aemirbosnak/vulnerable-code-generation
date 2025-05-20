//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_COLORS 7

typedef struct {
    int node;
    int color;
} GraphNode;

GraphNode graph[MAX_NODES];
int num_nodes;
int num_colors;

bool is_valid_color(int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[i].color == color)
            return false;
    }
    return true;
}

void color_graph() {
    int colors[MAX_COLORS] = {1, 2, 3, 4, 5, 6, 7};
    int num_colors_used = 0;

    for (int i = 0; i < num_nodes; i++) {
        int color = 0;
        while (!is_valid_color(color)) {
            color = rand() % num_colors;
        }
        graph[i].color = color;
        colors[color - 1] = 0;
        num_colors_used++;
    }

    printf("The minimum number of colors needed is %d.\n", num_colors_used);
}

int main() {
    srand(time(NULL));

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of colors to use (between 1 and %d): ", MAX_COLORS - 1);
    scanf("%d", &num_colors);

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the neighbors of node %d separated by spaces: ", i + 1);
        scanf("%d", &graph[i].node);
    }

    color_graph();

    return 0;
}
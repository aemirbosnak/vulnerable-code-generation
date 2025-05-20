//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10

typedef struct node {
    int color;
    int adjacent[MAX_NODES];
} node_t;

node_t nodes[MAX_NODES];
int num_nodes;

int main() {
    int i, j, k;
    int num_colors = 4;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);

    for (i = 0; i < num_nodes; i++) {
        nodes[i].color = -1;
        for (j = 0; j < MAX_NODES; j++) {
            nodes[i].adjacent[j] = -1;
        }
    }

    printf("Enter the edges of the graph:\n");
    for (i = 0; i < num_nodes - 1; i++) {
        scanf("%d", &nodes[i].adjacent[i]);
    }

    for (k = 1; k < num_nodes; k++) {
        if (nodes[k].adjacent[0]!= -1) {
            nodes[k].adjacent[0] = nodes[0].adjacent[k];
            nodes[0].adjacent[k] = k;
        }

        for (j = 1; j < k; j++) {
            if (nodes[k].adjacent[j]!= -1 && nodes[k].adjacent[j]!= nodes[j].adjacent[k]) {
                nodes[j].adjacent[k] = nodes[k].adjacent[j];
                nodes[k].adjacent[j] = j;
            }
        }
    }

    printf("Enter the number of colors for the graph:\n");
    scanf("%d", &num_colors);

    printf("Enter the colors for the graph:\n");
    for (i = 0; i < num_nodes; i++) {
        scanf("%d", &nodes[i].color);
    }

    bool is_valid = true;
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            if (nodes[i].adjacent[j]!= -1 && nodes[i].color == nodes[j].color) {
                is_valid = false;
                break;
            }
        }
        if (!is_valid) {
            break;
        }
    }

    if (is_valid) {
        printf("The graph is valid.\n");
    } else {
        printf("The graph is not valid.\n");
    }

    return 0;
}
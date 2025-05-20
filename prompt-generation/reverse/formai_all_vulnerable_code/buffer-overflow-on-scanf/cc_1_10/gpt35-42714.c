//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 50

typedef struct Node {
    int num;
    int degree;
    int color;
    int adj[MAX_NODES];
} Node;

Node nodes[MAX_NODES];
int num_nodes;

void add_edge(int u, int v) {
    nodes[u].adj[nodes[u].degree++] = v;
    nodes[v].adj[nodes[v].degree++] = u;
}

void greedy_coloring() {
    int colors[MAX_NODES];
    bool available[MAX_NODES];
    int i, j, k;

    for (i = 0; i < num_nodes; i++) {
        colors[i] = -1;
        available[i] = true;
    }

    colors[0] = 0;

    for (i = 1; i < num_nodes; i++) {
        for (j = 0; j < nodes[i].degree; j++) {
            k = nodes[i].adj[j];
            if (colors[k] != -1) {
                available[colors[k]] = false;
            }
        }

        for (j = 0; j < num_nodes; j++) {
            if (available[j]) {
                break;
            }
        }

        colors[i] = j;

        for (j = 0; j < nodes[i].degree; j++) {
            k = nodes[i].adj[j];
            if (colors[k] != -1) {
                available[colors[k]] = true;
            }
        }
    }

    printf("Vertex\tColor\n");
    for (i = 0; i < num_nodes; i++) {
        printf("%d\t%d\n", nodes[i].num, colors[i]);
    }
}

int main() {
    int i, j, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (i = 0; i < num_nodes; i++) {
        nodes[i].num = i;
        nodes[i].degree = 0;
        nodes[i].color = -1;
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            scanf("%d", &k);
            if (k == 1) {
                add_edge(i, j);
            }
        }
    }

    greedy_coloring();

    return 0;
}
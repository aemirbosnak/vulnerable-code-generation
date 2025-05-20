//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int color;
    int neighbors[4];
} node;

typedef struct graph {
    int V;
    node nodes[5];
} graph;

int main() {
    graph graph_instance;
    int V = 5;

    // Create graph nodes
    graph_instance.V = V;
    for (int i = 0; i < V; i++) {
        graph_instance.nodes[i].color = -1;
        graph_instance.nodes[i].neighbors[0] = -1;
        graph_instance.nodes[i].neighbors[1] = -1;
        graph_instance.nodes[i].neighbors[2] = -1;
        graph_instance.nodes[i].neighbors[3] = -1;
    }

    // Connect graph nodes
    graph_instance.nodes[0].neighbors[0] = 1;
    graph_instance.nodes[1].neighbors[0] = 1;
    graph_instance.nodes[2].neighbors[1] = 1;
    graph_instance.nodes[3].neighbors[1] = 1;
    graph_instance.nodes[4].neighbors[0] = 1;

    // Graph coloring algorithm
    int count = 0;
    int colors[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < V; i++) {
        if (graph_instance.nodes[i].color == -1) {
            for (int j = 0; j < V; j++) {
                if (graph_instance.nodes[i].neighbors[j]!= -1 && graph_instance.nodes[i].color == graph_instance.nodes[j].color) {
                    graph_instance.nodes[i].color = (graph_instance.nodes[i].color + 1) % 6;
                }
            }
            count++;
        }
    }

    if (count == V) {
        printf("Graph is %d-colorable.\n", count);
    } else {
        printf("Graph is not %d-colorable.\n", count);
    }

    return 0;
}
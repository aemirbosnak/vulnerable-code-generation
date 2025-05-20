//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_NEIGHBORS 1000
#define MAX_COLORS 1000

typedef struct node_t {
    int id;
    int num_neighbors;
    int *neighbors;
    int color;
} node_t;

void add_neighbor(node_t *node, int neighbor_id) {
    if (node->num_neighbors == MAX_NEIGHBORS) {
        printf("Error: Maximum number of neighbors reached.\n");
        exit(1);
    }
    node->neighbors[node->num_neighbors++] = neighbor_id;
}

void print_graph(node_t *nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", nodes[i].id);
        for (int j = 0; j < nodes[i].num_neighbors; j++) {
            printf("%d ", nodes[i].neighbors[j]);
        }
        printf("\n");
    }
}

bool is_valid_color(node_t *nodes, int num_nodes, int node_id, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].color == color && i!= node_id) {
            return false;
        }
    }
    return true;
}

void color_graph(node_t *nodes, int num_nodes) {
    int num_colors = 0;
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].color = num_colors++;
    }
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    node_t *nodes = malloc(num_nodes * sizeof(node_t));

    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].num_neighbors = 0;
        nodes[i].neighbors = malloc(MAX_NEIGHBORS * sizeof(int));
    }

    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        add_neighbor(&nodes[node1], node2);
        add_neighbor(&nodes[node2], node1);
    }

    color_graph(nodes, num_nodes);

    print_graph(nodes, num_nodes);

    free(nodes);

    return 0;
}
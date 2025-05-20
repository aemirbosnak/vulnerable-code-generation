//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

typedef struct {
    int id;
    char name[32];
    int num_links;
    int *links;
} Node;

void add_link(Node *node1, Node *node2) {
    node1->num_links++;
    node1->links = realloc(node1->links, sizeof(int) * node1->num_links);
    node1->links[node1->num_links - 1] = node2->id;
    node2->num_links++;
    node2->links = realloc(node2->links, sizeof(int) * node2->num_links);
    node2->links[node2->num_links - 1] = node1->id;
}

int main() {
    int num_nodes, i, j;
    Node *nodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    nodes = malloc(sizeof(Node) * num_nodes);

    for (i = 0; i < num_nodes; i++) {
        printf("Enter the ID and name of node %d: ", i + 1);
        scanf("%d %s", &nodes[i].id, nodes[i].name);
        nodes[i].num_links = 0;
        nodes[i].links = NULL;
    }

    printf("Enter the links between nodes (format: node1_id node2_id):\n");
    while (scanf("%d %d", &i, &j) == 2) {
        add_link(&nodes[i - 1], &nodes[j - 1]);
    }

    for (i = 0; i < num_nodes; i++) {
        printf("Node %d (%s) has %d links:\n", i + 1, nodes[i].name, nodes[i].num_links);
        for (j = 0; j < nodes[i].num_links; j++) {
            printf("  Node %d (%s)", nodes[i].links[j] + 1, nodes[(i + 1) * nodes[i].links[j] - 1].name);
        }
        printf("\n");
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 200

typedef struct {
    char name[20];
    int id;
    int links[MAX_LINKS];
    int num_links;
} node_t;

void add_link(node_t *node1, node_t *node2) {
    int i;
    for (i = 0; i < node1->num_links; i++) {
        if (node1->links[i] == node2->id) {
            return;
        }
    }
    node1->links[node1->num_links++] = node2->id;
}

void print_node(node_t *node) {
    printf("Name: %s\n", node->name);
    printf("ID: %d\n", node->id);
    printf("Links: ");
    int i;
    for (i = 0; i < node->num_links; i++) {
        printf("%d ", node->links[i]);
    }
    printf("\n");
}

void print_topology(node_t *nodes, int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d:\n", i);
        print_node(nodes + i);
    }
}

int main() {
    node_t nodes[MAX_NODES];
    int num_nodes = 0;

    while (num_nodes < MAX_NODES && scanf("%s", nodes[num_nodes].name)!= EOF) {
        nodes[num_nodes].id = num_nodes;
        num_nodes++;
    }

    int i, j, k;
    for (i = 0; i < num_nodes; i++) {
        printf("Enter number of links for node %s:\n", nodes[i].name);
        scanf("%d", &k);
        nodes[i].num_links = k;
        nodes[i].links[0] = i;
        j = 1;
        while (j < k) {
            printf("Enter ID of linked node:\n");
            scanf("%d", &nodes[i].links[j++]);
            add_link(nodes + i, nodes + nodes[i].links[j - 1]);
        }
    }

    print_topology(nodes, num_nodes);

    return 0;
}
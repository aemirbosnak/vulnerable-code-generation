//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

typedef struct {
    int id;
    char name[50];
    int links[MAX_LINKS];
    int num_links;
} node_t;

void add_link(node_t *node1, node_t *node2) {
    node1->links[node1->num_links++] = node2->id;
    node2->links[node2->num_links++] = node1->id;
}

void print_links(node_t *node, int depth) {
    for (int i = 0; i < node->num_links; i++) {
        printf("%*s-> %d\n", depth, node->name, node->links[i]);
    }
}

void print_tree(node_t *node, int depth) {
    printf("%*s%d\n", depth, "", node->id);
    print_links(node, depth + 2);
    for (int i = 0; i < node->num_links; i++) {
        print_tree(node->links[i], depth + 4);
    }
}

int main() {
    node_t nodes[MAX_NODES];
    int num_nodes = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the name of node %d: ", i + 1);
        scanf("%s", nodes[i].name);
        nodes[i].id = i + 1;
    }

    printf("Enter the links (format: node1->node2): ");
    char link_str[100];
    scanf("%s", link_str);

    char *token = strtok(link_str, "->");
    while (token!= NULL) {
        int node1_id, node2_id;
        sscanf(token, "%d", &node1_id);
        sscanf(strtok(NULL, "->"), "%d", &node2_id);
        add_link(&nodes[node1_id - 1], &nodes[node2_id - 1]);
        token = strtok(NULL, "->");
    }

    printf("Network topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        print_tree(&nodes[i], 0);
    }

    return 0;
}
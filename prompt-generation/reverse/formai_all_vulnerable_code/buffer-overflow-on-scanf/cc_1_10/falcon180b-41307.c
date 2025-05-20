//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 100

typedef struct {
    char name[20];
    int num_links;
    int links[MAX_LINKS];
} Node;

void add_node(Node *nodes, int num_nodes, char *name) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            printf("Node already exists.\n");
            return;
        }
    }
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].num_links = 0;
}

void add_link(Node *nodes, int num_nodes, int node1, int node2) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, "") == 0) {
            printf("Invalid node name.\n");
            return;
        }
    }
    nodes[node1].links[nodes[node1].num_links++] = node2;
    nodes[node2].links[nodes[node2].num_links++] = node1;
}

void print_nodes(Node *nodes, int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("%s (%d links)\n", nodes[i].name, nodes[i].num_links);
    }
}

int main() {
    Node nodes[MAX_NODES];
    int num_nodes = 0;
    char name[20];
    while (1) {
        printf("Enter node name (blank to stop): ");
        scanf("%s", name);
        if (strcmp(name, "") == 0) {
            break;
        }
        add_node(nodes, num_nodes, name);
        num_nodes++;
    }
    printf("Enter links (format: node1 node2):\n");
    while (1) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        if (node1 < 0 || node1 >= num_nodes || node2 < 0 || node2 >= num_nodes) {
            printf("Invalid node numbers.\n");
            continue;
        }
        add_link(nodes, num_nodes, node1, node2);
    }
    print_nodes(nodes, num_nodes);
    return 0;
}
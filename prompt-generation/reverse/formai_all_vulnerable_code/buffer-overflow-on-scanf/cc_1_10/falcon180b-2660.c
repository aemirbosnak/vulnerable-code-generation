//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    char name[20];
    int id;
    int connections[MAX_NODES];
    int num_connections;
} Node;

void add_connection(Node *node1, Node *node2) {
    int i, j;
    for (i = 0; i < node1->num_connections; i++) {
        if (node1->connections[i] == node2->id) {
            return;
        }
    }
    for (j = 0; j < node2->num_connections; j++) {
        if (node2->connections[j] == node1->id) {
            return;
        }
    }
    node1->connections[node1->num_connections] = node2->id;
    node2->connections[node2->num_connections] = node1->id;
    node1->num_connections++;
    node2->num_connections++;
}

void print_node(Node *node) {
    printf("Node %s (%d) connections: ", node->name, node->id);
    for (int i = 0; i < node->num_connections; i++) {
        printf("%d ", node->connections[i]);
    }
    printf("\n");
}

int main() {
    Node nodes[MAX_NODES];
    int num_nodes = 0;

    while (num_nodes < MAX_NODES) {
        printf("Enter node name (or 'done' to finish): ");
        scanf("%s", nodes[num_nodes].name);
        if (strcmp(nodes[num_nodes].name, "done") == 0) {
            break;
        }
        nodes[num_nodes].id = num_nodes + 1;
        num_nodes++;
    }

    printf("Enter connections (node1 node2):\n");
    while (1) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        if (node1 < 1 || node1 >= num_nodes || node2 < 1 || node2 >= num_nodes) {
            printf("Invalid node IDs.\n");
            continue;
        }
        add_connection(&nodes[node1 - 1], &nodes[node2 - 1]);
    }

    for (int i = 0; i < num_nodes; i++) {
        print_node(&nodes[i]);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_CONNECTIONS 200

typedef struct {
    int id;
    char name[50];
    bool is_router;
    int connections[MAX_CONNECTIONS];
    int num_connections;
} Node;

void add_connection(Node* node1, Node* node2) {
    int i;
    for(i = 0; i < node1->num_connections; i++) {
        if(node1->connections[i] == node2->id) {
            return;
        }
    }
    node1->connections[node1->num_connections++] = node2->id;
}

void print_node(Node* node) {
    printf("ID: %d\nName: %s\nIs Router: %s\n", node->id, node->name, node->is_router? "Yes" : "No");
}

void print_network_topology(Node* nodes, int num_nodes) {
    int i;
    for(i = 0; i < num_nodes; i++) {
        printf("Node %d:\n", i+1);
        print_node(nodes + i);
        printf("\nConnections:\n");
        int j;
        for(j = 0; j < nodes[i].num_connections; j++) {
            printf("- Node %d\n", nodes[nodes[i].connections[j]].id+1);
        }
    }
}

int main() {
    int num_nodes;
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &num_nodes);

    Node* nodes = malloc(num_nodes * sizeof(Node));

    int i;
    for(i = 0; i < num_nodes; i++) {
        printf("Enter the details for Node %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &nodes[i].id);
        printf("Name: ");
        scanf("%s", nodes[i].name);
        printf("Is Router? (y/n): ");
        scanf(" %c", &nodes[i].is_router);
        nodes[i].num_connections = 0;
    }

    int from_node, to_node;
    while(true) {
        printf("\nEnter two node IDs to connect (or 0 to stop):\n");
        scanf("%d %d", &from_node, &to_node);
        if(from_node == 0 && to_node == 0) {
            break;
        }
        add_connection(nodes + from_node - 1, nodes + to_node - 1);
    }

    print_network_topology(nodes, num_nodes);

    free(nodes);
    return 0;
}
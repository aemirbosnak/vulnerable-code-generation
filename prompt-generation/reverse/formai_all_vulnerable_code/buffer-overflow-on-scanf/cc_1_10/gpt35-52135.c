//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_NETWORK_SIZE 100 // Maximum number of nodes in the network

// The structure for each node in the network
typedef struct {
    int id;
    int connections[MAX_NETWORK_SIZE];
    int num_connections;
} node;

// Function to add a connection between two nodes
void add_connection(node *n1, node *n2) {
    n1->connections[n1->num_connections++] = n2->id;
    n2->connections[n2->num_connections++] = n1->id;
}

int main() {
    node network[MAX_NETWORK_SIZE];
    int num_nodes, node_id, num_connections, connection_id;

    // Get user input for number of nodes in the network
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &num_nodes);

    // Initialize each node in the network
    for (int i = 0; i < num_nodes; i++) {
        network[i].id = i;
        network[i].num_connections = 0;
    }

    // Get user input for each node's connections
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the number of connections for node %d: ", i);
        scanf("%d", &num_connections);

        for (int j = 0; j < num_connections; j++) {
            printf("Enter the ID of connection %d for node %d: ", j, i);
            scanf("%d", &connection_id);

            // Add the connection between the two nodes
            add_connection(&network[i], &network[connection_id]);
        }
    }

    // Print out the network topology
    printf("\n\nNetwork Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d:", i);
        for (int j = 0; j < network[i].num_connections; j++) {
            printf(" %d", network[i].connections[j]);
        }
        printf("\n");
    }

    return 0;
}
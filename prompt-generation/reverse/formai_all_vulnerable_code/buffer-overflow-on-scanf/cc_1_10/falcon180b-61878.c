//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100

// Define the structure for each node in the network
typedef struct node {
    char name[20];
    int num_connections;
    int connections[MAX_NODES];
} Node;

// Function to compare two nodes based on their names
int compare_nodes(const void *a, const void *b) {
    const Node *node1 = (const Node *)a;
    const Node *node2 = (const Node *)b;
    return strcmp(node1->name, node2->name);
}

// Function to print the network topology
void print_network(Node nodes[], int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("%s: ", nodes[i].name);
        int j;
        for (j = 0; j < nodes[i].num_connections; j++) {
            printf("%s ", nodes[i].connections[j] == -1? "None" : nodes[i].connections[j]);
        }
        printf("\n");
    }
}

int main() {
    int num_nodes, i, j;
    Node nodes[MAX_NODES];

    // Read in the number of nodes
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &num_nodes);

    // Read in the names and connections for each node
    printf("Enter the names and connections for each node:\n");
    for (i = 0; i < num_nodes; i++) {
        scanf("%s", nodes[i].name);
        printf("Enter the number of connections for %s: ", nodes[i].name);
        scanf("%d", &nodes[i].num_connections);

        // Read in the connections for this node
        int conn;
        for (j = 0; j < nodes[i].num_connections; j++) {
            scanf("%d", &conn);
            nodes[i].connections[j] = conn;
        }
    }

    // Sort the nodes alphabetically
    qsort(nodes, num_nodes, sizeof(Node), compare_nodes);

    // Print the network topology
    printf("Network topology:\n");
    print_network(nodes, num_nodes);

    return 0;
}
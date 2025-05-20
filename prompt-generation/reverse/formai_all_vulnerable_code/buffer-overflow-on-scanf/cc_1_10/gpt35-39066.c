//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 15
#define MAX_CONNECTIONS 20

typedef struct node {
    char label[20];
    int num_connections;
    char connections[MAX_CONNECTIONS][20];
} Node;

Node network[MAX_NODES];
int num_nodes = 0;

void add_node(char* label) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached!\n");
        return;
    }
    Node n;
    strcpy(n.label, label);
    n.num_connections = 0;
    network[num_nodes++] = n;
}

void add_connection(char* n1, char* n2) {
    int found1 = 0, found2 = 0;
    int i,j;
    for (i=0; i<num_nodes; i++) {
        if (strcmp(network[i].label, n1) == 0) {
            found1 = 1;
            for (j=0; j<network[i].num_connections; j++) {
                if (strcmp(network[i].connections[j], n2) == 0) {
                    return; // connection already exists
                }
            }
            if (network[i].num_connections >= MAX_CONNECTIONS) {
                printf("Error: Maximum number of connections reached for node %s!\n", n1);
                return;
            }
            strcpy(network[i].connections[network[i].num_connections++], n2);
        }
        if (strcmp(network[i].label, n2) == 0) {
            found2 = 1;
            if (network[i].num_connections >= MAX_CONNECTIONS) {
                printf("Error: Maximum number of connections reached for node %s!\n", n2);
                return;
            }
            strcpy(network[i].connections[network[i].num_connections++], n1);
        }
    }
    if (!found1) {
        printf("Error: Node %s not found!\n", n1);
    }
    if (!found2) {
        printf("Error: Node %s not found!\n", n2);
    }
}

void print_network_map() {
    printf("-------- Network Topology Map --------\n");
    int i,j;
    for (i=0; i<num_nodes; i++) {
        printf("%s --> ", network[i].label);
        for (j=0; j<network[i].num_connections; j++) {
            printf("%s ", network[i].connections[j]);
        }
        printf("\n");
    }
}

int main() {
    printf("--- C Network Topology Mapper ---\n");
    printf("Commands: \n");
    printf("  add_node [label]\n");
    printf("  add_connection [node1] [node2]\n");
    printf("  print_map\n");
    printf("  quit\n");
    printf("---------------------------------\n");

    char cmd[50];
    char arg1[20];
    char arg2[20];
    while (1) {
        printf("Enter command: ");
        scanf("%s", cmd);
        if (strcmp(cmd, "add_node") == 0) {
            scanf("%s", arg1);
            add_node(arg1);
        }
        else if (strcmp(cmd, "add_connection") == 0) {
            scanf("%s %s", arg1, arg2);
            add_connection(arg1, arg2);
        }
        else if (strcmp(cmd, "print_map") == 0) {
            print_network_map();
        }
        else if (strcmp(cmd, "quit") == 0) {
            break;
        }
        else {
            printf("Unknown command.\n");
        }
    }
    return 0;
}
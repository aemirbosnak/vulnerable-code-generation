//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int adjacents[MAX_NODES];
    int num_adjacents;
} Node;

Node network[MAX_NODES];
int node_count = 0;

// Function to add a node
void add_node(const char* name) {
    if (node_count < MAX_NODES) {
        strncpy(network[node_count].name, name, MAX_NAME_LENGTH);
        network[node_count].num_adjacents = 0;
        node_count++;
        printf("Node '%s' added to the network.\n", name);
    } else {
        printf("Maximum nodes reached. Cannot add '%s'.\n", name);
    }
}

// Function to connect two nodes
void connect_nodes(const char* node1, const char* node2) {
    int idx1 = -1, idx2 = -1;
    
    for (int i = 0; i < node_count; i++) {
        if (strcmp(network[i].name, node1) == 0) {
            idx1 = i;
        }
        if (strcmp(network[i].name, node2) == 0) {
            idx2 = i;
        }
    }
    
    if (idx1 != -1 && idx2 != -1) {
        network[idx1].adjacents[network[idx1].num_adjacents++] = idx2;
        network[idx2].adjacents[network[idx2].num_adjacents++] = idx1;
        printf("Connected '%s' and '%s'.\n", node1, node2);
    } else {
        printf("One or both nodes not found.\n");
    }
}

// Function to display the network
void display_network() {
    printf("\nCurrent Network Topology:\n");
    for (int i = 0; i < node_count; i++) {
        printf("\nNode: %s\nConnections: ", network[i].name);
        for (int j = 0; j < network[i].num_adjacents; j++) {
            printf("%s ", network[network[i].adjacents[j]].name);
        }
        printf("\n");
    }
}

int main() {
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];
    int choice;

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Connect Nodes\n");
        printf("3. Display Network\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", name1);
                add_node(name1);
                break;
            case 2:
                printf("Enter first node name: ");
                scanf("%s", name1);
                printf("Enter second node name: ");
                scanf("%s", name2);
                connect_nodes(name1, name2);
                break;
            case 3:
                display_network();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
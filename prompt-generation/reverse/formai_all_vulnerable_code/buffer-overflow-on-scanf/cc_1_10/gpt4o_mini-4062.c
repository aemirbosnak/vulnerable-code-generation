//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define NODE_NAME_LEN 20

typedef struct Node {
    char name[NODE_NAME_LEN];
    int connected_nodes[MAX_NODES];
    int connection_count;
} Node;

Node network_nodes[MAX_NODES];
int node_count = 0;

void add_node(const char *name) {
    if (node_count < MAX_NODES) {
        strncpy(network_nodes[node_count].name, name, NODE_NAME_LEN);
        network_nodes[node_count].connection_count = 0;
        node_count++;
    } else {
        printf("Cannot add more nodes. Maximum limit reached!\n");
    }
}

void connect_nodes(const char *name1, const char *name2) {
    int index1 = -1, index2 = -1;

    for (int i = 0; i < node_count; i++) {
        if (strcmp(network_nodes[i].name, name1) == 0) {
            index1 = i;
        }
        if (strcmp(network_nodes[i].name, name2) == 0) {
            index2 = i;
        }
    }
    
    if (index1 != -1 && index2 != -1 && index1 != index2) {
        network_nodes[index1].connected_nodes[network_nodes[index1].connection_count++] = index2;
        network_nodes[index2].connected_nodes[network_nodes[index2].connection_count++] = index1;
    } else {
        printf("One or both nodes not found, or trying to connect a node to itself!\n");
    }
}

void display_topology() {
    printf("\n--- Network Topology ---\n");
    
    for (int i = 0; i < node_count; i++) {
        printf("Node: %s\n", network_nodes[i].name);
        printf("Connected to: ");
        for (int j = 0; j < network_nodes[i].connection_count; j++) {
            printf("%s ", network_nodes[network_nodes[i].connected_nodes[j]].name);
        }
        printf("\n");
    }
}

void cleanup_network() {
    for (int i = 0; i < node_count; i++) {
        network_nodes[i].connection_count = 0;  // Reset connection counts
    }
    node_count = 0;  // Clear all nodes
}

int main() {
    int choice;
    char name1[NODE_NAME_LEN], name2[NODE_NAME_LEN];

    do {
        printf("\n1. Add Node\n");
        printf("2. Connect Nodes\n");
        printf("3. Display Topology\n");
        printf("4. Cleanup Network\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                fgets(name1, NODE_NAME_LEN, stdin);
                name1[strcspn(name1, "\n")] = '\0'; // remove newline
                add_node(name1);
                break;
            case 2:
                printf("Enter first node name: ");
                fgets(name1, NODE_NAME_LEN, stdin);
                name1[strcspn(name1, "\n")] = '\0'; // remove newline
                printf("Enter second node name: ");
                fgets(name2, NODE_NAME_LEN, stdin);
                name2[strcspn(name2, "\n")] = '\0'; // remove newline
                connect_nodes(name1, name2);
                break;
            case 3:
                display_topology();
                break;
            case 4:
                cleanup_network();
                printf("Network cleaned up! Ready for a new beginning...\n");
                break;
            case 5:
                printf("Exiting the ruins...\n");
                break;
            default:
                printf("Invalid choice, try again...\n");
        }
    } while (choice != 5);

    return 0;
}
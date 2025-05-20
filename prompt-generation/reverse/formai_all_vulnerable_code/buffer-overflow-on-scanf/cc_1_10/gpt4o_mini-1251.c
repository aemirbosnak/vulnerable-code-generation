//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node *connections[MAX_NODES];
    int connection_count;
} Node;

typedef struct Network {
    Node *nodes[MAX_NODES];
    int node_count;
} Network;

Network* create_network() {
    Network *network = (Network *)malloc(sizeof(Network));
    network->node_count = 0;
    return network;
}

Node* create_node(const char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    new_node->connection_count = 0;
    return new_node;
}

int add_node(Network *network, const char *name) {
    if (network->node_count >= MAX_NODES) {
        printf("Cannot add more nodes. Max limit reached.\n");
        return -1;
    }
    Node *node = create_node(name);
    network->nodes[network->node_count++] = node;
    return 0;
}

Node* find_node(Network *network, const char *name) {
    for (int i = 0; i < network->node_count; i++) {
        if (strcmp(network->nodes[i]->name, name) == 0) {
            return network->nodes[i];
        }
    }
    return NULL;
}

int add_connection(Network *network, const char *source_name, const char *dest_name) {
    Node *source = find_node(network, source_name);
    Node *destination = find_node(network, dest_name);
    if (source && destination) {
        if (source->connection_count >= MAX_NODES) {
            printf("Cannot add more connections from %s. Max limit reached.\n", source_name);
            return -1;
        }
        source->connections[source->connection_count++] = destination;
        return 0;
    }
    printf("Error: Node(s) not found.\n");
    return -1;
}

void display_network(Network *network) {
    printf("Current Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node *node = network->nodes[i];
        printf("Node: %s is connected to:", node->name);
        for (int j = 0; j < node->connection_count; j++) {
            printf(" %s", node->connections[j]->name);
        }
        printf("\n");
    }
}

void free_network(Network *network) {
    for (int i = 0; i < network->node_count; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network *network = create_network();
    int choice;
    char name[MAX_NAME_LENGTH];
    char source[MAX_NAME_LENGTH], destination[MAX_NAME_LENGTH];

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Display Network\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                add_node(network, name);
                break;
            case 2:
                printf("Enter source node name: ");
                fgets(source, MAX_NAME_LENGTH, stdin);
                source[strcspn(source, "\n")] = 0;  // Remove newline character
                printf("Enter destination node name: ");
                fgets(destination, MAX_NAME_LENGTH, stdin);
                destination[strcspn(destination, "\n")] = 0;  // Remove newline character
                add_connection(network, source, destination);
                break;
            case 3:
                display_network(network);
                break;
            case 4:
                free_network(network);
                exit(0);
            default:
                printf("Invalid option, try again.\n");
                break;
        }
    }
    return 0;
}
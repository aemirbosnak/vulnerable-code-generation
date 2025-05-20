//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_CONNECTIONS 10

typedef struct Node {
    int id;
    char name[20];
    struct Node* connections[MAX_CONNECTIONS];
    int connection_count;
} Node;

Node* nodes[MAX_NODES];
int node_count = 0;

Node* create_node(int id, const char* name) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->id = id;
    strncpy(new_node->name, name, sizeof(new_node->name) - 1);
    new_node->connection_count = 0;
    return new_node;
}

void add_node(const char* name) {
    if (node_count < MAX_NODES) {
        nodes[node_count] = create_node(node_count, name);
        node_count++;
        printf("Node '%s' added with ID %d\n", name, node_count - 1);
    } else {
        printf("Node limit reached! Cannot add more nodes.\n");
    }
}

void add_connection(int id1, int id2) {
    if (id1 >= node_count || id2 >= node_count) {
        printf("Invalid node IDs: %d, %d\n", id1, id2);
        return;
    }
    Node* node1 = nodes[id1];
    Node* node2 = nodes[id2];

    if (node1->connection_count < MAX_CONNECTIONS && node2->connection_count < MAX_CONNECTIONS) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1; // Assuming undirected graph
        printf("Connection added between '%s' and '%s'\n", node1->name, node2->name);
    } else {
        printf("Connection limit reached for nodes '%s' or '%s'\n", node1->name, node2->name);
    }
}

void display_topology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < node_count; i++) {
        Node* node = nodes[i];
        printf("Node %d (%s): ", node->id, node->name);
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char name[20];
    int id1, id2;

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Display Topology\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", name);
                add_node(name);
                break;
            case 2:
                printf("Enter first node ID: ");
                scanf("%d", &id1);
                printf("Enter second node ID: ");
                scanf("%d", &id2);
                add_connection(id1, id2);
                break;
            case 3:
                display_topology();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }

    return 0;
}
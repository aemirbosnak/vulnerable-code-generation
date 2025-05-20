//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int connections[MAX_NODES];
    int conn_count;
} Node;

Node nodes[MAX_NODES];
int node_count = 0;

void addNode(const char *name) {
    if (node_count >= MAX_NODES) {
        printf("Maximum node limit reached.\n");
        return;
    }
    strcpy(nodes[node_count].name, name);
    nodes[node_count].conn_count = 0;
    node_count++;
}

void addConnection(int node1, int node2) {
    if (node1 >= node_count || node2 >= node_count) {
        printf("Invalid node index.\n");
        return;
    }
    nodes[node1].connections[nodes[node1].conn_count++] = node2;
    nodes[node2].connections[nodes[node2].conn_count++] = node1;  // Assuming undirected connection
}

void displayTopology() {
    printf("Network Topology:\n");
    for (int i = 0; i < node_count; i++) {
        printf("%s: ", nodes[i].name);
        for (int j = 0; j < nodes[i].conn_count; j++) {
            printf("%s ", nodes[nodes[i].connections[j]].name);
        }
        printf("\n");
    }
}

int findNodeByName(const char *name) {
    for (int i = 0; i < node_count; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Node not found
}

void menu() {
    printf("\nNetwork Topology Mapper:\n");
    printf("1. Add Node\n");
    printf("2. Add Connection\n");
    printf("3. Display Topology\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", name);
                addNode(name);
                break;

            case 2: {
                int node1, node2;
                printf("Enter first node name: ");
                scanf("%s", name);
                node1 = findNodeByName(name);
                printf("Enter second node name: ");
                scanf("%s", name);
                node2 = findNodeByName(name);
                
                if (node1 != -1 && node2 != -1) {
                    addConnection(node1, node2);
                } else {
                    printf("One or both node(s) not found.\n");
                }
                break;
            }

            case 3:
                displayTopology();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_NAME_LENGTH 20

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int connections[MAX_NODES];
    int connection_count;
} Node;

Node nodes[MAX_NODES];
int node_count = 0;

// Function declarations
void addNode(const char *name);
void addConnection(const char *name1, const char *name2);
void displayTopology();
int findNodeIndex(const char *name);

int main() {
    int choice;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Display Topology\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                fgets(name1, MAX_NAME_LENGTH, stdin);
                name1[strcspn(name1, "\n")] = 0; // Remove newline character
                addNode(name1);
                break;
            case 2:
                printf("Enter first node name: ");
                fgets(name1, MAX_NAME_LENGTH, stdin);
                name1[strcspn(name1, "\n")] = 0;
                printf("Enter second node name: ");
                fgets(name2, MAX_NAME_LENGTH, stdin);
                name2[strcspn(name2, "\n")] = 0;
                addConnection(name1, name2);
                break;
            case 3:
                displayTopology();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addNode(const char *name) {
    if (node_count < MAX_NODES) {
        strcpy(nodes[node_count].name, name);
        nodes[node_count].connection_count = 0;
        node_count++;
        printf("Node '%s' added successfully.\n", name);
    } else {
        printf("Unable to add node. Maximum limit reached!\n");
    }
}

void addConnection(const char *name1, const char *name2) {
    int index1 = findNodeIndex(name1);
    int index2 = findNodeIndex(name2);

    if (index1 == -1 || index2 == -1) {
        printf("One or both nodes not found.\n");
        return;
    }

    if (nodes[index1].connection_count < MAX_NODES && 
        nodes[index2].connection_count < MAX_NODES) {
        nodes[index1].connections[nodes[index1].connection_count++] = index2;
        nodes[index2].connections[nodes[index2].connection_count++] = index1;
        printf("Connection between '%s' and '%s' added successfully.\n", name1, name2);
    } else {
        printf("Connection cannot be added. One or both nodes have reached maximum connections!\n");
    }
}

void displayTopology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < node_count; i++) {
        printf("Node %s connects to: ", nodes[i].name);
        for (int j = 0; j < nodes[i].connection_count; j++) {
            printf("%s ", nodes[nodes[i].connections[j]].name);
        }
        printf("\n");
    }
}

int findNodeIndex(const char *name) {
    for (int i = 0; i < node_count; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Node not found
}
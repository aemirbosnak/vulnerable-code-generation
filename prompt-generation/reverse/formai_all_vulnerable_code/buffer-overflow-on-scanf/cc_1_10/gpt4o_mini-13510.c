//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_CONNECTIONS 5

typedef struct Node {
    char name[20];
    int connections[MAX_CONNECTIONS];
    int connectionCount;
} Node;

Node network[MAX_NODES];
int nodeCount = 0;

void addNode(char *name) {
    if (nodeCount < MAX_NODES) {
        strcpy(network[nodeCount].name, name);
        network[nodeCount].connectionCount = 0;
        nodeCount++;
        printf("🎉 Node '%s' added successfully! 🎉\n", name);
    } else {
        printf("😞 Can't add '%s', node limit reached! 😞\n", name);
    }
}

void addConnection(char *node1, char *node2) {
    int index1 = -1, index2 = -1;
    
    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(network[i].name, node1) == 0) {
            index1 = i;
        }
        if (strcmp(network[i].name, node2) == 0) {
            index2 = i;
        }
    }
    
    if (index1 != -1 && index2 != -1) {
        if (network[index1].connectionCount < MAX_CONNECTIONS &&
            network[index2].connectionCount < MAX_CONNECTIONS) {
            network[index1].connections[network[index1].connectionCount++] = index2;
            network[index2].connections[network[index2].connectionCount++] = index1;
            printf("✨ Connection established between '%s' and '%s'! ✨\n", node1, node2);
        } else {
            printf("💔 One of the nodes already has maximum connections! 💔\n");
        }
    } else {
        printf("😢 One of the nodes doesn't exist! 😢\n");
    }
}

void displayTopology() {
    printf("\n🕸️ Network Topology 🕸️\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node '%s' is connected to: ", network[i].name);
        for (int j = 0; j < network[i].connectionCount; j++) {
            printf("'%s' ", network[network[i].connections[j]].name);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char node1[20], node2[20];
    
    printf("✨ Welcome to the Network Topology Mapper! ✨\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Display Topology\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        getchar();  // Clear newline left by scanf
        
        switch (choice) {
            case 1:
                printf("Enter the name of the node: ");
                fgets(node1, sizeof(node1), stdin);
                node1[strcspn(node1, "\n")] = 0;  // Remove newline
                addNode(node1);
                break;
            case 2:
                printf("Enter the names of the nodes to connect (e.g., NodeA NodeB): ");
                scanf("%s %s", node1, node2);
                addConnection(node1, node2);
                break;
            case 3:
                displayTopology();
                break;
            case 4:
                printf("🎈 Thank you for using the Network Topology Mapper! Goodbye! 🎈\n");
                exit(0);
            default:
                printf("🚫 Invalid choice! Please try again! 🚫\n");
        }
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: QR code reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the QR code struct
typedef struct {
    char message[256];
} QRCode;

// Define the decentralized node struct
typedef struct {
    char id[256];
    bool is_active;
    QRCode qr_code;
} Node;

// Initialize the node array
Node nodes[10];

// Define function to read QR code
void readQRCode(QRCode *qr_code) {
    printf("Scan QR code:\n");
    scanf("%s", qr_code->message);
}

// Define function to add node
void addNode(char *id) {
    int i, empty_slot=-1;
    for (i = 0; i < sizeof(nodes)/sizeof(Node); i++) {
        if (strcmp(nodes[i].id, id) == 0) {
            printf("Node already exists!\n");
            return;
        }
        if (empty_slot == -1 && !nodes[i].is_active) {
            empty_slot = i;
        }
    }
    if (empty_slot != -1) {
        nodes[empty_slot].is_active = true;
        strcpy(nodes[empty_slot].id, id);
        readQRCode(&nodes[empty_slot].qr_code);
        printf("Node added successfully!\n");
    } else {
        printf("No more nodes can be added!\n");
    }
}

// Define function to remove node
void removeNode(char *id) {
    int i;
    for (i = 0; i < sizeof(nodes)/sizeof(Node); i++) {
        if (strcmp(nodes[i].id, id) == 0) {
            nodes[i].is_active = false;
            printf("Node removed successfully!\n");
            return;
        }
    }
    printf("Node not found!\n");
}

// Define function to display all active nodes
void displayActiveNodes() {
    int i, count = 0;
    printf("Active Nodes:\n");
    for (i = 0; i < sizeof(nodes)/sizeof(Node); i++) {
        if (nodes[i].is_active) {
            printf("%d. %s\n", ++count, nodes[i].id);
        }
    }
    if (count == 0) {
        printf("No active nodes found!\n");
    }
}

// Define function to read QR code for a specific node
void readQRCodeForNode() {
    int i;
    char id[256];
    printf("Enter node id:");
    scanf("%s", id);
    for (i = 0; i < sizeof(nodes)/sizeof(Node); i++) {
        if (strcmp(nodes[i].id, id) == 0) {
            readQRCode(&nodes[i].qr_code);
            printf("QR code updated successfully!\n");
            return;
        }
    }
    printf("Node not found!\n");
}

// Main function
int main() {
    int choice;
    char id[256];
    while (true) {
        printf("\n----------MENU----------\n");
        printf("1. Add node\n");
        printf("2. Remove node\n");
        printf("3. Display active nodes\n");
        printf("4. Read QR code for a specific node\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter node id:");
                scanf("%s", id);
                addNode(id);
                break;
            case 2:
                printf("Enter node id:");
                scanf("%s", id);
                removeNode(id);
                break;
            case 3:
                displayActiveNodes();
                break;
            case 4:
                readQRCodeForNode();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
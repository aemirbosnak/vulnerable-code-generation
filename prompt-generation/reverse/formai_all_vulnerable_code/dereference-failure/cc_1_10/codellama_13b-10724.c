//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
// Program: Unique C Network Topology Mapper Example
// Author: [Your Name]
// Date: [Today's Date]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a network node
typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

// Function to add a node to the network
void addNode(Node** head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the network
void printNetwork(Node* head) {
    while (head != NULL) {
        printf("%s -> ", head->name);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create a network
    Node* head = NULL;
    addNode(&head, "Node 1");
    addNode(&head, "Node 2");
    addNode(&head, "Node 3");
    addNode(&head, "Node 4");
    addNode(&head, "Node 5");

    // Print the network
    printNetwork(head);

    return 0;
}
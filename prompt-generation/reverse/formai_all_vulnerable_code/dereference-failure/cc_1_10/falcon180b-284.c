//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the graph
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Traverse the list until the end is reached
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Add the new node at the end
    temp->next = newNode;
    newNode->next = NULL;
}

// Function to print the graph in a recursive manner
void printGraph(Node* head) {
    if (head == NULL) {
        printf("Empty graph\n");
        return;
    }

    // Print the first node
    printf("%d -> ", head->data);

    // Recursively print the rest of the nodes
    Node* temp = head->next;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    // Print a newline character at the end
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Add nodes to the graph
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the graph
    printf("Graph: ");
    printGraph(head);

    return 0;
}
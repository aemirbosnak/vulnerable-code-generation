//Falcon-180B DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** head, char data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    // Check if the list is empty
    if (temp == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the end of the list
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Add the new node at the end
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, 'a');
    addNode(&head, 'b');
    addNode(&head, 'c');

    // Print the list
    printf("Linked list: ");
    printList(head);

    // Free the memory used by the list
    Node* temp = head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}
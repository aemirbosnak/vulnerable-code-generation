//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
typedef struct node {
    char data;
    struct node* next;
} Node;

// Linked list functions
Node* createNode(char data);
void printList(Node* head);
void insertNode(Node** head, char data);
void deleteNode(Node** head, char data);

int main() {
    Node* head = NULL;

    // Create linked list
    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'c');

    // Print linked list
    printf("Linked list before deletion:\n");
    printList(head);

    // Delete node
    deleteNode(&head, 'b');

    // Print linked list after deletion
    printf("\nLinked list after deletion:\n");
    printList(head);

    return 0;
}

// Create node with given data
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
}

// Insert node with given data at the beginning of the list
void insertNode(Node** head, char data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Delete node with given data from the list
void deleteNode(Node** head, char data) {
    Node* temp = *head;
    Node* prev = NULL;

    // If head node is to be deleted
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for node to be deleted
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    // If node not found
    if (temp == NULL)
        return;

    // Unlink node from list
    prev->next = temp->next;
    free(temp);
}
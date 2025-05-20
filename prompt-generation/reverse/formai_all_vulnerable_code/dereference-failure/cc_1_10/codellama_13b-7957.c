//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
/// A beginner-friendly Linked list operations example program in C

#include <stdio.h>
#include <stdlib.h>

/// Node structure for a Linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/// Function to create a new node
Node* createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/// Function to insert a node at the beginning of the Linked list
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

/// Function to insert a node at the end of the Linked list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/// Function to insert a node after a given node
void insertAfter(Node **head, int data, int position) {
    Node *newNode = createNode(data);
    Node *temp = *head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

/// Function to delete a node at a given position
void deleteNode(Node **head, int position) {
    Node *temp = *head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

/// Function to print the Linked list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAfter(&head, 15, 1);
    insertAtEnd(&head, 30);
    deleteNode(&head, 3);
    printList(head);
    return 0;
}
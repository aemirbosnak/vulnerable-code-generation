//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
/*
 * Linked list operations in a post-apocalyptic style
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>

/* Node structure for the linked list */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Function to create a new node */
Node* createNode(int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Function to insert a node at the beginning of the list */
void insertAtBeginning(Node **head, int data) {
    Node *node = createNode(data);
    node->next = *head;
    *head = node;
}

/* Function to insert a node at the end of the list */
void insertAtEnd(Node **head, int data) {
    Node *node = createNode(data);
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

/* Function to insert a node after a specific node */
void insertAfter(Node **head, int data, int target) {
    Node *node = createNode(data);
    Node *temp = *head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target not found\n");
    } else {
        node->next = temp->next;
        temp->next = node;
    }
}

/* Function to delete a node from the list */
void deleteNode(Node **head, int data) {
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
    } else {
        if (prev == NULL) {
            *head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

/* Function to display the list */
void displayList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 3);
    insertAfter(&head, 4, 1);
    insertAfter(&head, 5, 3);
    displayList(head);
    deleteNode(&head, 2);
    displayList(head);
    return 0;
}
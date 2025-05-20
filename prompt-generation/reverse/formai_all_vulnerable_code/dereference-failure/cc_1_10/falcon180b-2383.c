//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    char data[100];
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void addNode(Node** head, char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the list recursively
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// Function to delete a node from the list
void deleteNode(Node** head, char* data) {
    if (*head == NULL) {
        return;
    }
    if (strcmp(data, (*head)->data) == 0) {
        *head = (*head)->next;
        return;
    }
    Node* temp = *head;
    while (temp->next!= NULL && strcmp(data, temp->next->data)!= 0) {
        temp = temp->next;
    }
    if (temp->next!= NULL) {
        temp->next = temp->next->next;
    }
}

int main() {
    Node* head = NULL;
    char input[100];

    // Add nodes to the list
    addNode(&head, "Hello");
    addNode(&head, "World");
    addNode(&head, "How");
    addNode(&head, "are");
    addNode(&head, "you?");

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    // Print the reversed list
    printf("\nReversed list:\n");
    printList(head);

    // Delete a node
    deleteNode(&head, "are");

    // Print the list after deletion
    printf("\nList after deletion:\n");
    printList(head);

    return 0;
}
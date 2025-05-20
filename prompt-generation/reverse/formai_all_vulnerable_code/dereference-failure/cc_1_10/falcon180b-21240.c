//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Node structure for Linked List
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp = *head;

    // Traverse to the end of the list
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Add the new node
    temp->next = newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node from the list
void deleteNode(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;

    // Traverse to the node to be deleted
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    // If the node is the head
    if (prev == NULL) {
        *head = temp->next;
        free(temp);
        return;
    }

    // If the node is in the middle or at the end
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node* head = NULL;

    // Insert nodes
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 0);
    insertAtEnd(&head, 3);

    // Print the list
    printList(head);

    // Delete a node
    deleteNode(&head, 1);

    // Print the list again
    printList(head);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node** head) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 1;
    newNode->next = NULL;

    // Set the new node as the head of the list
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        // Traverse to the end of the list
        struct Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        // Add the new node to the end of the list
        temp->next = newNode;
    }
}

void printList(struct Node* head) {
    // Traverse the list and print each node's data
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNode(struct Node** head, int key) {
    // Traverse the list and find the node with the given key
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    // If the node was found, delete it
    if (temp!= NULL) {
        if (prev == NULL) {
            *head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

void reverseList(struct Node** head) {
    // Traverse the list and reverse the links
    struct Node* prev = NULL;
    struct Node* curr = *head;
    while (curr!= NULL) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void main() {
    // Create a new list with 5 nodes
    struct Node* head = NULL;
    createList(&head);
    printList(head);

    // Delete a node with data 3
    deleteNode(&head, 3);
    printList(head);

    // Reverse the list
    reverseList(&head);
    printList(head);
}
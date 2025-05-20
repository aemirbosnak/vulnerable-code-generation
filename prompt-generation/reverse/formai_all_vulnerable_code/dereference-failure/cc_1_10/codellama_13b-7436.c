//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
/*
 * Linked list operations example program
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* node = createNode(data);
    node->next = *head;
    *head = node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* node = createNode(data);
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

// Function to insert a node after a given node
void insertAfter(struct Node** head, int data, int position) {
    struct Node* node = createNode(data);
    struct Node* current = *head;
    while (current->next != NULL && position > 0) {
        current = current->next;
        position--;
    }
    node->next = current->next;
    current->next = node;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int position) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    while (current->next != NULL && position > 0) {
        previous = current;
        current = current->next;
        position--;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAfter(&head, 3, 1);
    insertAfter(&head, 4, 3);
    display(head);
    deleteNode(&head, 2);
    display(head);
    return 0;
}
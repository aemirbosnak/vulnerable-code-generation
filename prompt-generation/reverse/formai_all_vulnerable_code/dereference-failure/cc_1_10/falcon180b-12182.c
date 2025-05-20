//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node after a given position
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node by key
void deleteNode(struct Node *head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head node itself holds the key or if list is empty
    if (temp!= NULL && temp->data == key) {
        head = temp->next;
        free(temp);            
        return;
    }

    // Delete node with given key
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Add 7 to the beginning.
    push(&head, 7);

    // Add 1 at the beginning.
    push(&head, 1);

    // Add 6 at the end.
    push(&head, 6);

    // Add 4 at position 2.
    insertAfter(head->next, 4);

    // Print the list.
    printf("Created Linked List: ");
    printList(head);

    // Delete node which has data as 1.
    deleteNode(head, 1);

    // Print the list after deleting 1.
    printf("\nLinked List after deleting first node: ");
    printList(head);

    return 0;
}
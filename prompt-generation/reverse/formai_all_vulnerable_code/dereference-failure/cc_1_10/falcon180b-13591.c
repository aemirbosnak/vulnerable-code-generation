//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory error\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node after a given position in the list
void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node with given data from the list
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev;

    // If head node itself holds the key or if the list is empty
    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;   
        free(temp);            
        return;
    }

    // Delete node with the given key
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

// Function to search for a node with given data in the list
Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    Node* head = NULL;

    // Insert 7 at the beginning.
    push(&head, 7);

    // Insert 1 at the beginning.
    push(&head, 1);

    // Insert 6 at the end.
    Node* last = searchNode(head, 6);
    insertAfter(last, 6);

    // Delete node which has data as 1.
    deleteNode(&head, 1);

    // Print the list
    printf("List after deleting node with value 1: \n");
    printList(head);

    return 0;
}
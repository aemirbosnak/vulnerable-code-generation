//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;

    return;
}

// Function to add a node after a given position
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    return;
}

// Function to delete a node by key
void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key or if list is empty
    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
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
    return;
}

// Function to search for a node by key
struct Node* search(struct Node* head, int x) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Add nodes
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);

    // Print the list
    printf("Original List: ");
    printList(head);

    // Append a node
    append(&head, 4);
    printf("\nList after appending 4: ");
    printList(head);

    // Insert a node after position 3
    struct Node* temp = search(head, 3);
    insertAfter(temp, 8);
    printf("\nList after inserting 8 after 3: ");
    printList(head);

    // Delete a node by key
    deleteNode(&head, 1);
    printf("\nList after deleting 1: ");
    printList(head);

    return 0;
}
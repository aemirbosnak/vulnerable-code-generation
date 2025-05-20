//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the beginning of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = create_node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = create_node(new_data);
    Node* last = *head_ref;

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
void insert_after(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    Node* new_node = create_node(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    return;
}

// Function to delete a node by key
void delete_node(Node **head_ref, int key) {
    Node* temp = *head_ref, *prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);            
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void print_list(Node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Driver code
int main() {
    Node* head = NULL;

    // Add 7 to the beginning.
    push(&head, 7);

    // Add 1 to the end.
    append(&head, 1);

    // Add 6 at position 1.
    insert_after(head->next, 6);

    // Print the list.
    printf("Created Linked List: ");
    print_list(head);

    return 0;
}
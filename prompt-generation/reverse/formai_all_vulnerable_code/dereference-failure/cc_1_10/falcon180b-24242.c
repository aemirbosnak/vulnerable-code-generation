//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(struct node** head_ref, int new_data) {
    struct node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(struct node** head_ref, int new_data) {
    struct node* new_node = newNode(new_data);
    struct node* last = *head_ref;

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
void addNode(struct node **head_ref, int data, int position) {
    struct node* new_node = newNode(data);
    struct node* temp = *head_ref;

    if (position == 0) {
        new_node->next = temp;
        *head_ref = new_node;
        return;
    }

    int i = 0;
    while (temp!= NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
        printf("Position out of range");
    else {
        new_node->next = temp->next;
        temp->next = new_node;
    }

    return;
}

// Function to delete a node by key
void deleteNode(struct node **head_ref, int key) {
    struct node* temp = *head_ref;
    struct node* prev;

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
    return;
}

// Function to search for a node by key
struct node* search(struct node* head, int key) {
    struct node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;

    // Add nodes
    push(&head, 7);
    push(&head, 1);
    append(&head, 6);

    // Print list
    printf("Created Linked List: ");
    printList(head);

    // Add node at position 2
    addNode(&head, 4, 2);

    // Print updated list
    printf("\nList after adding node at position 2: ");
    printList(head);

    // Delete node with key 1
    deleteNode(&head, 1);

    // Print updated list
    printf("\nList after deleting node with key 1: ");
    printList(head);

    // Search for node with key 7
    struct node* found_node = search(head, 7);
    if (found_node!= NULL)
        printf("\nNode with key 7 found in the list");
    else
        printf("\nNode with key 7 not found in the list");

    return 0;
}
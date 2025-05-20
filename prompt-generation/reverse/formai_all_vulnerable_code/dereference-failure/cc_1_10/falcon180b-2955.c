//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
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

// Function to add a node after a given position in the list
void insertAfter(struct node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    struct node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    return;
}

// Function to delete a node from the list
void deleteNode(struct node **head_ref, struct node* del) {
    struct node* temp = *head_ref;

    if (temp == del) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->next!= del)
        temp = temp->next;

    if (temp == NULL)
        return;

    temp->next = temp->next->next;
    free(del);

    return;
}

// Function to search for a node in the list
struct node* search(struct node* head, int x) {
    struct node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;

    // Add nodes to the list
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    // Print the list
    printf("List after adding nodes: ");
    printList(head);

    // Append a node to the end of the list
    append(&head, 50);

    // Print the list
    printf("\nList after appending a node: ");
    printList(head);

    // Insert a node after a given position in the list
    struct node* pos_node = search(head, 20);
    if (pos_node!= NULL) {
        insertAfter(pos_node, 25);
    }

    // Print the list
    printf("\nList after inserting a node: ");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, search(head, 30));

    // Print the list
    printf("\nList after deleting a node: ");
    printList(head);

    return 0;
}
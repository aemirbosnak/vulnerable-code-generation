//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
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

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
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

    struct Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    return;
}

// Function to delete a node from the list
void deleteNode(struct Node **head_ref, struct Node* del) {
    struct Node* temp = *head_ref;
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

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    // Add some nodes
    push(&head, 7);
    push(&head, 1);
    append(&head, 6);
    insertAfter(head->next, 4);

    // Print the list
    printf("Created Linked List: ");
    printList(head);

    // Delete a node
    deleteNode(&head, head->next->next);

    // Print the list after deletion
    printf("\nLinked List after deleting 4: ");
    printList(head);

    return 0;
}
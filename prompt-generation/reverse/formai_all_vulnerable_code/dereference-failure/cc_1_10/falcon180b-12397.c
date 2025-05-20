//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
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

// Function to add a node at the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
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

// Function to add a node after a specified position in the list
void addNode(Node** head_ref, int data, int pos) {
    Node* new_node = newNode(data);
    Node* temp = *head_ref;

    if (pos == 0) {
        new_node->next = temp;
        *head_ref = new_node;
        return;
    }

    for (int i = 0; i < pos - 1 && temp!= NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        printf("\nThe position entered is out of range.\n");
    else {
        new_node->next = temp->next;
        temp->next = new_node;
    }

    return;
}

// Function to delete a node from the list
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("\nThe key entered is not present in the list.\n");
    else {
        prev->next = temp->next;
        free(temp);
    }

    return;
}

// Function to search for a node in the list
Node* search(Node* head, int key) {
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

    // Add nodes to the list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    append(&head, 4);

    // Print the list
    printf("\nThe list is: ");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 2);

    // Print the list after deletion
    printf("\nThe list after deleting node with value 2 is: ");
    printList(head);

    return 0;
}
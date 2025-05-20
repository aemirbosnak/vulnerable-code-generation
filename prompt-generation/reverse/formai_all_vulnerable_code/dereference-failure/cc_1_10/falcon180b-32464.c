//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: unmistakable
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
    printf("%d added to the beginning of the list\n", new_data);
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        printf("%d added to the end of the list\n", new_data);
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    printf("%d added to the end of the list\n", new_data);
}

// Function to add a node at a specific position
void addAtPosition(struct Node **head_ref, int new_data, int pos) {
    struct Node* new_node = newNode(new_data);
    struct Node* temp = *head_ref;
    int i;

    if (pos == 0) {
        new_node->next = temp;
        *head_ref = new_node;
        printf("%d added at the beginning of the list\n", new_data);
        return;
    }

    for (i = 0; i < pos - 1; i++) {
        if (temp!= NULL)
            temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    printf("%d added at position %d\n", new_data, pos);
}

// Function to delete a node by key
void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("%d deleted from the list\n", key);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("%d not found in the list\n", key);
    else {
        prev->next = temp->next;
        free(temp);
        printf("%d deleted from the list\n", key);
    }
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

    // Add nodes to the list
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    append(&head, 40);
    addAtPosition(&head, 50, 2);

    // Print the list
    printf("Original list: ");
    printList(head);

    // Delete a node
    deleteNode(&head, 20);

    // Print the list after deletion
    printf("\nList after deleting 20: ");
    printList(head);

    return 0;
}
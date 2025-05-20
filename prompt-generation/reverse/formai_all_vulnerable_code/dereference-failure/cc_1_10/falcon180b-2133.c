//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: rigorous
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

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;
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

// Function to add a node at a specific position in the list
void addAtPosition(struct Node** head_ref, int new_data, int pos) {
    struct Node* new_node = newNode(new_data);
    struct Node* temp = *head_ref;
    if (pos == 0) {
        new_node->next = temp;
        *head_ref = new_node;
        return;
    }
    int i;
    for (i = 0; i < pos - 1 && temp!= NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        printf("Invalid position\n");
    else {
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Function to delete a node at a specific position in the list
void deleteNode(struct Node** head_ref, int pos) {
    struct Node* temp = *head_ref;
    struct Node* prev;
    if (pos == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    int i;
    for (i = 0; i < pos - 1 && temp!= NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        printf("Invalid position\n");
    else {
        prev->next = temp->next;
        free(temp);
    }
}

// Function to display the list
void display(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 10);
    push(&head, 15);
    append(&head, 20);
    append(&head, 25);
    display(head);
    addAtPosition(&head, 30, 1);
    display(head);
    deleteNode(&head, 2);
    display(head);
    return 0;
}
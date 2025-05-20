//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add element at beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add element at end of the list
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

// Function to add element at specified position
void addAtPosition(struct Node** head_ref, int data, int pos) {
    struct Node* new_node = newNode(data);
    struct Node* temp = *head_ref;

    if (pos == 0) {
        new_node->next = temp;
        *head_ref = new_node;
        return;
    }

    int i;
    for (i = 0; temp!= NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL)
        printf("Invalid position\n");
    else {
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Function to delete node by key
void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev;

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
        return;

    prev->next = temp->next;
    free(temp);
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

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);

    printf("Linked List: \n");
    display(head);

    append(&head, 4);
    printf("\nAfter appending 4: \n");
    display(head);

    addAtPosition(&head, 0, 0);
    printf("\nAfter adding 0 at position 0: \n");
    display(head);

    addAtPosition(&head, 8, 6);
    printf("\nAfter adding 8 at position 6: \n");
    display(head);

    deleteNode(&head, 1);
    printf("\nAfter deleting 1: \n");
    display(head);

    deleteNode(&head, 6);
    printf("\nAfter deleting 6: \n");
    display(head);

    return 0;
}
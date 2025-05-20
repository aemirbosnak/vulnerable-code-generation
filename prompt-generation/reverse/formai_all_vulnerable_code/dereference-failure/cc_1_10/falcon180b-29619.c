//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
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
    printf("\n%d is pushed to the stack", new_data);
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
    printf("\n%d is appended to the stack", new_data);
}

// Function to remove a node from the list
void pop(struct Node **head_ref) {
    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
    printf("\nNode with data %d is deleted from the stack", temp->data);
}

// Function to display the list
void display(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    append(&head, 40);
    append(&head, 50);
    display(head);
    pop(&head);
    display(head);
    return 0;
}
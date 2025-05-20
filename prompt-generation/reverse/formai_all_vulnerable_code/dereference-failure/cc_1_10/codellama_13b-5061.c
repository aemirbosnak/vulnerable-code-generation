//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: romantic
/*
 * Linked list operations in a romantic style
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to insert a new node at the beginning of the list
void insert(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the list
void append(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to print the list
void print(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    append(&head, 4);
    append(&head, 5);

    print(head);

    return 0;
}
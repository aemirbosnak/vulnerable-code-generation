//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
// Linked list operations example program
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct node {
    int data;
    struct node *next;
};

// Function to insert a node at the end of a linked list
void insert_at_end(struct node **head_ref, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    struct node *current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to print a linked list
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    // Insert nodes at the end of the list
    insert_at_end(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);

    // Print the list
    print_list(head);

    // Free the list
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
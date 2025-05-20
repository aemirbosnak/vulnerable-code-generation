//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: future-proof
/*
 * Linked list operations example program in a future-proof style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
struct node* insert_beginning(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a new node at the end of the list
struct node* insert_end(struct node *head, int data) {
    struct node *new_node = create_node(data);
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Function to delete a node from the list
struct node* delete_node(struct node *head, int data) {
    struct node *current = head;
    struct node *prev = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                head = head->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

// Function to print the list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    // Insert elements in the list
    head = insert_beginning(head, 1);
    head = insert_beginning(head, 2);
    head = insert_beginning(head, 3);
    head = insert_end(head, 4);
    head = insert_end(head, 5);

    // Print the list
    print_list(head);

    // Delete an element from the list
    head = delete_node(head, 2);

    // Print the list again
    print_list(head);

    return 0;
}
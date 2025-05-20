//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: introspective
// Linked list operations example program

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
void insert_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the list
void insert_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to insert a new node after a given node
void insert_after(struct node *previous, int data) {
    struct node *new_node = create_node(data);
    new_node->next = previous->next;
    previous->next = new_node;
}

// Function to delete a node from the list
void delete_node(struct node **head, int data) {
    struct node *current = *head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
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

    // Insert nodes at the beginning of the list
    insert_beginning(&head, 10);
    insert_beginning(&head, 20);
    insert_beginning(&head, 30);

    // Insert nodes at the end of the list
    insert_end(&head, 40);
    insert_end(&head, 50);

    // Insert a node after a given node
    insert_after(head->next->next, 60);

    // Delete a node from the list
    delete_node(&head, 30);

    // Print the list
    print_list(head);

    return 0;
}
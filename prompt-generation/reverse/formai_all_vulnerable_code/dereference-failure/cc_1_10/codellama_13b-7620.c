//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to insert a new node after a given node in the linked list
void insert_after(struct Node** head_ref, int data, int position) {
    struct Node* new_node = create_node(data);
    struct Node* current = *head_ref;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(struct Node** head_ref, int position) {
    struct Node* current = *head_ref;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->next = current->next->next;
}

// Function to print the linked list
void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    // Initialize the head pointer to NULL
    struct Node* head = NULL;

    // Insert 5 nodes at the beginning
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 4);
    insert_at_beginning(&head, 5);

    // Insert 3 nodes at the end
    insert_at_end(&head, 6);
    insert_at_end(&head, 7);
    insert_at_end(&head, 8);

    // Insert 2 nodes after node at position 3
    insert_after(&head, 9, 3);
    insert_after(&head, 10, 3);

    // Delete node at position 5
    delete_node(&head, 5);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    return 0;
}
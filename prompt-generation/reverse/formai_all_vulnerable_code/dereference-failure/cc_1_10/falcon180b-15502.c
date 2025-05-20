//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void create_linked_list(Node** head);
void add_node(Node** head, int data);
void delete_node(Node** head, int data);
void print_linked_list(Node* head);
void free_linked_list(Node* head);

// Main function
int main() {
    Node* head = NULL;

    // Create linked list
    create_linked_list(&head);

    // Add nodes
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);

    // Print linked list
    print_linked_list(head);

    // Delete node
    delete_node(&head, 2);

    // Print linked list
    print_linked_list(head);

    // Free linked list
    free_linked_list(head);

    return 0;
}

// Function to create linked list
void create_linked_list(Node** head) {
    *head = NULL;
}

// Function to add node
void add_node(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to delete node
void delete_node(Node** head, int data) {
    Node* current_node = *head;
    Node* previous_node = NULL;

    while (current_node!= NULL && current_node->data!= data) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Node not found.\n");
    } else {
        if (previous_node == NULL) {
            *head = current_node->next;
        } else {
            previous_node->next = current_node->next;
        }
        free(current_node);
    }
}

// Function to print linked list
void print_linked_list(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free linked list
void free_linked_list(Node* head) {
    while (head!= NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
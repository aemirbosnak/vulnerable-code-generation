//Falcon-180B DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void create_node(Node** head, int data);
void delete_node(Node** head, int data);
void display_list(Node* head);

int main() {
    Node* head = NULL;

    // Allocate memory for linked list nodes
    head = (Node*) malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }

    // Initialize linked list
    create_node(&head, 1);
    create_node(&head, 2);
    create_node(&head, 3);

    // Display linked list
    printf("Linked List: ");
    display_list(head);

    // Delete node with data 2
    delete_node(&head, 2);

    // Display updated linked list
    printf("\nLinked List after deleting node with data 2: ");
    display_list(head);

    // Free memory allocated for linked list nodes
    free(head);

    return 0;
}

// Function to create a new node with given data
void create_node(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to delete a node with given data
void delete_node(Node** head, int data) {
    Node* temp = *head;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    Node* prev_node = temp->next;
    free(temp);
    temp = prev_node;
}

// Function to display linked list
void display_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
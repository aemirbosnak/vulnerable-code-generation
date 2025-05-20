//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: modular
// memory_management.c

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to allocate memory for a new node
Node* create_node(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a new node at the end of the linked list
void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to print the linked list
void print_list(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Function to free the memory of the linked list
void free_list(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    print_list(head);
    free_list(&head);
    return 0;
}
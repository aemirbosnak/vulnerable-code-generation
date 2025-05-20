//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: future-proof
/* Linked List Operations Example Program */

#include <stdio.h>
#include <stdlib.h>

// Define a structure to store the list elements
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to insert a node at the beginning of the list
void insert_beginning(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the list
void insert_end(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to delete a node from the list
void delete_node(Node **head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// Function to traverse the list
void traverse_list(Node **head) {
    if (*head == NULL) {
        return;
    }
    Node *current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a list
    Node *head = NULL;
    insert_beginning(&head, 10);
    insert_beginning(&head, 20);
    insert_beginning(&head, 30);
    insert_end(&head, 40);
    insert_end(&head, 50);
    insert_end(&head, 60);
    traverse_list(&head);
    delete_node(&head, 30);
    delete_node(&head, 60);
    traverse_list(&head);
    return 0;
}
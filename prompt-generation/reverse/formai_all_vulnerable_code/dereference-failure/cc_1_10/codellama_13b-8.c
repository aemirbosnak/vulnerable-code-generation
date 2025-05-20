//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
/*
 * Linked List Operations Example Program
 *
 * Author: Alan Turing
 * Date: 1948
 *
 * This program demonstrates various operations on a linked list
 * using C programming language.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to insert a new node at the beginning of the list
void insert_beginning(Node** head_ref, int data) {
    // Allocate memory for the new node
    Node* new_node = (Node*)malloc(sizeof(Node));

    // Put the data in the new node
    new_node->data = data;

    // Make next of new node as head
    new_node->next = *head_ref;

    // Move the head to point to the new node
    *head_ref = new_node;
}

// Function to insert a new node at the end of the list
void insert_end(Node** head_ref, int data) {
    // Create a new node
    Node* new_node = (Node*)malloc(sizeof(Node));

    // Put the data in the new node
    new_node->data = data;

    // Make next of new node as NULL
    new_node->next = NULL;

    // If the linked list is empty, make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Else traverse till the last node
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = new_node;
}

// Function to delete a node from the list
void delete_node(Node** head_ref, int data) {
    // If the head node itself holds the data to be deleted
    if ((*head_ref) != NULL && (*head_ref)->data == data) {
        // Store head node
        Node* temp = *head_ref;

        // Change head
        *head_ref = (*head_ref)->next;

        // Free old head
        free(temp);
        return;
    }

    // Else traverse the list and search for the node to be deleted
    Node* temp = *head_ref;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    // If node was not found, do nothing
    if (temp == NULL) {
        return;
    }

    // Unlink the node from list
    Node* node_to_delete = temp;
    temp = temp->next;
    node_to_delete->next = NULL;

    // Free memory
    free(node_to_delete);
}

// Function to print the list
void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test the above functions
int main() {
    // Start with the empty list
    Node* head = NULL;

    // Insert 5. So linked list becomes 5->NULL
    insert_beginning(&head, 5);

    // Insert 7 at the beginning. So linked list becomes 7->5->NULL
    insert_beginning(&head, 7);

    // Insert 1 at the end. So linked list becomes 7->5->1->NULL
    insert_end(&head, 1);

    // Insert 10 at the beginning. So linked list becomes 10->7->5->1->NULL
    insert_beginning(&head, 10);

    // Delete 5 from the list
    delete_node(&head, 5);

    // Print the list
    print_list(head);

    return 0;
}
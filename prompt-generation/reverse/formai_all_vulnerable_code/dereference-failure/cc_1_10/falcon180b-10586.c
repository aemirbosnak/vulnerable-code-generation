//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the linked list
typedef struct node {
    char data[100]; // Data stored in the node
    struct node *next; // Pointer to the next node in the list
} Node;

// Function to add a node to the end of the linked list
void append(Node **head, char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    strcpy(new_node->data, data); // Copy the data to the new node
    new_node->next = NULL; // Set the next pointer to NULL
    if (*head == NULL) {
        *head = new_node; // If the list is empty, set the head to the new node
        return;
    }
    Node *last_node = *head; // Get the last node in the list
    while (last_node->next!= NULL) { // Traverse the list until the end
        last_node = last_node->next;
    }
    last_node->next = new_node; // Set the next pointer of the last node to the new node
}

// Function to delete a node from the linked list
void delete_node(Node **head, char *data) {
    Node *curr_node = *head; // Get the head of the list
    Node *prev_node = NULL; // Initialize the previous node to NULL
    while (curr_node!= NULL && strcmp(curr_node->data, data)!= 0) { // Traverse the list until the node with the given data is found
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (curr_node == NULL) { // If the node with the given data is not found
        printf("Node not found.\n");
        return;
    }
    if (prev_node == NULL) { // If the node to be deleted is the head of the list
        *head = curr_node->next; // Set the head to the next node
        free(curr_node); // Free the memory allocated to the node
        return;
    }
    prev_node->next = curr_node->next; // Set the next pointer of the previous node to the next node
    free(curr_node); // Free the memory allocated to the node
}

// Function to print the linked list
void print_list(Node *head) {
    while (head!= NULL) { // Traverse the list until the end
        printf("%s -> ", head->data); // Print the data of the current node
        head = head->next; // Move to the next node
    }
    printf("NULL\n"); // Print NULL to indicate the end of the list
}

// Main function
int main() {
    Node *head = NULL; // Initialize the head of the list to NULL
    append(&head, "apple"); // Append a node with data "apple" to the end of the list
    append(&head, "banana"); // Append a node with data "banana" to the end of the list
    append(&head, "cherry"); // Append a node with data "cherry" to the end of the list
    print_list(head); // Print the list
    delete_node(&head, "banana"); // Delete the node with data "banana" from the list
    print_list(head); // Print the list
    delete_node(&head, "apple"); // Delete the node with data "apple" from the list
    print_list(head); // Print the list
    return 0;
}
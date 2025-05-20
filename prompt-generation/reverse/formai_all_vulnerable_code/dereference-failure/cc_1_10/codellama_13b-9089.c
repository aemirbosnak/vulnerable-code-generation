//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: high level of detail
/*
 * A program to demonstrate basic linked list operations in C.
 */
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to new node
    new_node->data = data;

    // Make next of new node as head
    new_node->next = *head_ref;

    // Change head to new node
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to new node
    new_node->data = data;

    // If list is empty, make new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = NULL;
        return;
    }

    // Find the last node of the list
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node to new node
    last->next = new_node;

    // Make new node as NULL
    new_node->next = NULL;
}

// Function to delete a node from the beginning of the list
void deleteAtBeginning(struct Node** head_ref) {
    // If list is empty, return
    if (*head_ref == NULL) {
        return;
    }

    // Store head node
    struct Node* temp = *head_ref;

    // Change head to head's next node
    *head_ref = temp->next;

    // Free memory for head node
    free(temp);
}

// Function to delete a node from the end of the list
void deleteAtEnd(struct Node** head_ref) {
    // If list is empty, return
    if (*head_ref == NULL) {
        return;
    }

    // If there is only one node in the list, delete it
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    // Find the last node of the list
    struct Node* last = *head_ref;
    while (last->next->next != NULL) {
        last = last->next;
    }

    // Free memory for last node
    free(last->next);

    // Change the next of last node to NULL
    last->next = NULL;
}

// Function to search for a node in the list
struct Node* search(struct Node** head_ref, int data) {
    // If list is empty, return NULL
    if (*head_ref == NULL) {
        return NULL;
    }

    // Iterate through the list
    struct Node* current = *head_ref;
    while (current != NULL) {
        // If data is found, return the node
        if (current->data == data) {
            return current;
        }

        // Go to the next node
        current = current->next;
    }

    // If data is not found, return NULL
    return NULL;
}

// Function to print the list
void printList(struct Node** head_ref) {
    // If list is empty, return
    if (*head_ref == NULL) {
        return;
    }

    // Iterate through the list
    struct Node* current = *head_ref;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    // Print NULL at the end of the list
    printf("NULL\n");
}

// Driver code
int main() {
    // Initialize the list
    struct Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Search for a node in the list
    struct Node* search_node = search(&head, 4);
    if (search_node != NULL) {
        printf("Node found: %d\n", search_node->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the beginning of the list
    deleteAtBeginning(&head);

    // Delete a node from the end of the list
    deleteAtEnd(&head);

    // Print the list
    printList(&head);

    // Free memory for the list
    free(head);

    return 0;
}
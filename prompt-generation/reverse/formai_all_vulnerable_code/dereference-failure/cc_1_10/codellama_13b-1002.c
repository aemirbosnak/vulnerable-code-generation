//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: visionary
// Linked list example program

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int i = 0;
    while (i < position && current->next != NULL) {
        current = current->next;
        i++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node
void deleteNode(struct Node** head, int position) {
    struct Node* current = *head;
    int i = 0;
    while (i < position && current->next != NULL) {
        current = current->next;
        i++;
    }
    if (i == position) {
        current->next = current->next->next;
        free(current->next);
    }
}

// Function to print the list
void printList(struct Node** head) {
    struct Node* current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a new list
    struct Node* head = NULL;

    // Insert some nodes at the beginning
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);

    // Insert some nodes at the end
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    // Insert a node after a given node
    insertAfter(&head, 5, 2);

    // Delete a node
    deleteNode(&head, 2);

    // Print the list
    printList(&head);

    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: active
// Linked list operations example program
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert a node at the beginning of the list
void insertFirst(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

// Insert a node at the end of the list
void insertLast(struct Node** head, int data) {
    struct Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

// Delete a node from the list
void delete(struct Node** head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        struct Node* temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

// Print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    // Initialize the list
    struct Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertFirst(&head, 1);
    insertFirst(&head, 2);

    // Insert some nodes at the end of the list
    insertLast(&head, 3);
    insertLast(&head, 4);
    insertLast(&head, 5);

    // Delete a node from the list
    delete(&head, 3);

    // Print the linked list
    printList(head);

    // Free the memory
    free(head);

    return 0;
}
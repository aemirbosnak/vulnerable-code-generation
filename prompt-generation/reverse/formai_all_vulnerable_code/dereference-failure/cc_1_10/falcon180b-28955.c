//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        new_node->next = NULL;
        (*head_ref) = new_node;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// Function to insert a node after a given position
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = new_data;
    node->next = prev_node->next;
    prev_node->next = node;
}

// Function to delete a node at a given position
void deleteNode(struct Node **head_ref, struct Node* del) {
    struct Node* temp = *head_ref;
    if (temp == del) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp!= del) {
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    struct Node* node = temp->next;
    temp->next = node->next;
    free(node);
}

// Function to search for a node with a given data value
struct Node* search(struct Node* head, int x) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    printList(head);
    append(&head, 0);
    printList(head);
    insertAfter(head->next, 2);
    printList(head);
    struct Node* searchNode = search(head, 0);
    if (searchNode!= NULL)
        printf("\nFound %d in the list", searchNode->data);
    else
        printf("\nNot found in the list");
    deleteNode(&head, head->next);
    printList(head);
    return 0;
}
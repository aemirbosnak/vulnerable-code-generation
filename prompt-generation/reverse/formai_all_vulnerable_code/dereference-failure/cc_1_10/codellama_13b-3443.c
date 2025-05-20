//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: intelligent
// Linked list operations example program in an intelligent style
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct node** head_ref, int data) {
    struct node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct node** head_ref, int data) {
    struct node* new_node = newNode(data);
    struct node* last = *head_ref;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to insert a new node after a given node
void insertAfter(struct node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("The given previous node does not exist\n");
        return;
    }

    struct node* new_node = newNode(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node
void deleteNode(struct node** head_ref, int data) {
    struct node* temp = *head_ref;
    struct node* prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("The given node does not exist\n");
        return;
    }

    if (prev == NULL) {
        *head_ref = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Function to print the linked list
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAfter(head->next, 4);
    printList(head);

    deleteNode(&head, 2);
    printList(head);

    return 0;
}
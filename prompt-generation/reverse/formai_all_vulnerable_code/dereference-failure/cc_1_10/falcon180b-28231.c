//Falcon-180B DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void addNode(struct node** head, int data) {
    struct node* node = newNode(data);
    struct node* temp = *head;

    if (*head == NULL) {
        node->next = NULL;
        *head = node;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = node;
    node->next = NULL;
}

// Function to delete a node with given data
void deleteNode(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);

    // Print the list
    printf("Original List: ");
    printList(head);

    // Delete a node
    deleteNode(&head, 3);

    // Print the list after deletion
    printf("\nList after deleting 3: ");
    printList(head);

    return 0;
}
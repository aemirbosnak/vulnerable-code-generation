//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// node structure definition
struct Node {
    int data;
    struct Node* next;
};

// function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("%d is pushed to the stack\n", new_data);
}

// function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    printf("%d is appended to the stack\n", new_data);
}

// function to add a node after a given position
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    printf("%d is inserted after %d\n", new_data, prev_node->data);
}

// function to delete a node by key
void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key or if list is empty
    if (temp!= NULL && temp->data == key) {
        temp = temp->next;
        *head_ref = temp;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);  // Free memory
    printf("%d is deleted from the stack\n", key);
}

// function to print the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// driver code
int main() {
    struct Node* head = NULL;

    // Let us create the linked list: 8->6->4->2
    head = newNode(8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);

    // print the linked list
    printf("Created Linked List: ");
    printList(head);

    // append a node
    append(&head, 10);
    printf("\nNode with value 10 is appended\n");
    printList(head);

    // insert a node after a given position
    insertAfter(head->next, 7);
    printf("\nNode with value 7 is inserted after 6\n");
    printList(head);

    // delete a node
    deleteNode(&head, 6);
    printf("\nNode with value 6 is deleted from the list\n");
    printList(head);

    return 0;
}
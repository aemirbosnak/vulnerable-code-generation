//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node* next;
};

// Function prototypes
void addNode(struct node** head, int data);
void deleteNode(struct node** head, int data);
void printList(struct node* head);
void reverseList(struct node** head);

int main() {
    struct node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the list
    printf("Original list: ");
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print the reversed list
    printf("\nReversed list: ");
    printList(head);

    // Delete nodes from the list
    deleteNode(&head, 1);
    deleteNode(&head, 3);
    deleteNode(&head, 5);

    // Print the updated list
    printf("\nUpdated list: ");
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the list
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

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse the list
void reverseList(struct node** head) {
    struct node* prev = NULL;
    struct node* current = *head;

    while (current!= NULL) {
        struct node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}
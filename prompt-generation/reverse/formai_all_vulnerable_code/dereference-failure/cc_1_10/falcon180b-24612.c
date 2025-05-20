//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void printList(Node* head);
void freeList(Node* head);

// Main function
int main() {
    Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Free the list
    freeList(head);

    return 0;
}

// Add a node to the end of the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List:\n");
        Node* temp = head;
        while (temp!= NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Free the list
void freeList(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}
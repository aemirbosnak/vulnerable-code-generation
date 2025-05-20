//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the linked list
void addNode(struct Node** head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error: Could not allocate memory for new node.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }
    printf("List: ");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    while (head!= NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Test case 1: Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    printList(head);

    // Test case 2: Add nodes until memory is full
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        addNode(&head, i);
    }
    printf("Maximum size reached. Cannot add more nodes.\n");

    // Test case 3: Free the memory allocated for the list
    freeList(head);
    printf("Memory freed.\n");

    return 0;
}
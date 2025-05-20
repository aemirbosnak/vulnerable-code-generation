//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add element to linked list
void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to search element in linked list
struct Node* search(struct Node* head, int data) {
    struct Node* current = head;

    while (current!= NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data;

    // Add elements to linked list
    while (1) {
        printf("\nEnter 1 to add element, 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        printf("Enter element to add: ");
        scanf("%d", &data);
        addNode(&head, data);
    }

    // Search element in linked list
    printf("\nEnter element to search: ");
    scanf("%d", &data);
    struct Node* result = search(head, data);

    if (result!= NULL) {
        printf("\nElement found at position %d", result->data);
    } else {
        printf("\nElement not found");
    }

    return 0;
}
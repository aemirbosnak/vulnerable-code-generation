//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    // Create a new node with given data
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse the list until the end is reached
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Add the new node to the end of the list
    temp->next = newNode;
}

void printList(struct Node* head) {
    // Traverse the list and print each node's data
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchList(struct Node* head, int target) {
    // Traverse the list and search for the target element
    struct Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == target) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct Node* head = NULL;

    // Insert some elements into the list
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    insertNode(&head, 20);
    insertNode(&head, 25);

    // Print the list
    printf("Original list: ");
    printList(head);

    // Search for an element in the list
    int target = 15;
    if (searchList(head, target)) {
        printf("%d found in the list.\n", target);
    } else {
        printf("%d not found in the list.\n", target);
    }

    // Free the memory allocated for the list
    struct Node* temp = head;
    while (temp!= NULL) {
        head = temp->next;
        free(temp);
        temp = head;
    }

    return 0;
}
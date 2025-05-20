//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a linked list
struct Node* createLinkedList(int numNodes) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* current = NULL;

    for (int i = 0; i < numNodes; i++) {
        current = (struct Node*)malloc(sizeof(struct Node));
        current->data = i;
        current->next = NULL;

        if (head == NULL) {
            head = current;
            tail = current;
        } else {
            tail->next = current;
            tail = current;
        }
    }

    return head;
}

// Print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;

    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Reverse the linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;

    while (current!= NULL) {
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Sort the linked list
struct Node* sortLinkedList(struct Node* head) {
    struct Node* current = head;
    struct Node* next = NULL;

    while (current!= NULL && current->next!= NULL) {
        if (current->data > current->next->data) {
            int tempData = current->data;
            current->data = current->next->data;
            current->next->data = tempData;
        }
        current = current->next;
    }

    return head;
}

int main() {
    int numNodes = 10;
    struct Node* head = createLinkedList(numNodes);
    printf("Original linked list:\n");
    printLinkedList(head);

    head = reverseLinkedList(head);
    printf("Reversed linked list:\n");
    printLinkedList(head);

    head = sortLinkedList(head);
    printf("Sorted linked list:\n");
    printLinkedList(head);

    return 0;
}
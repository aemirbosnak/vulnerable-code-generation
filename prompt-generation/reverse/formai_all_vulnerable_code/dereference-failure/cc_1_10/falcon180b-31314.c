//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the end of the list
void push(struct Node** head_ref, int new_data) {
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

    return;
}

// Function to display the elements of the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to reverse the list
struct Node* reverseList(struct Node* head) {
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

// Function to sort the list in ascending order
struct Node* sortList(struct Node* head) {
    struct Node* cur = head;
    struct Node* nxt;
    int temp;

    while (cur!= NULL && cur->next!= NULL) {
        if (cur->data > cur->next->data) {
            temp = cur->data;
            cur->data = cur->next->data;
            cur->next->data = temp;
        }
        cur = cur->next;
    }

    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    // Display the elements of the list
    printf("Original list:\n");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    // Display the reversed list
    printf("\nReversed list:\n");
    printList(head);

    // Sort the list in ascending order
    head = sortList(head);

    // Display the sorted list
    printf("\nSorted list:\n");
    printList(head);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for our linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Create a linked list with 10 nodes, each containing a number from 1 to 10
Node* createLinkedList() {
    Node* head = NULL;
    Node* curr = NULL;
    int i;

    for (i = 1; i <= 10; i++) {
        curr = (Node*) malloc(sizeof(Node));
        curr->data = i;
        curr->next = NULL;

        if (head == NULL) {
            head = curr;
        } else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = curr;
        }
    }

    return head;
}

// Print out the values in our linked list
void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create our linked list
    Node* head = createLinkedList();

    // Print out the initial values
    printf("Initial linked list:\n");
    printLinkedList(head);

    // Reverse the linked list
    Node* prev = NULL;
    Node* curr = head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    // Print out the reversed linked list
    printf("\nReversed linked list:\n");
    printLinkedList(head);

    return 0;
}
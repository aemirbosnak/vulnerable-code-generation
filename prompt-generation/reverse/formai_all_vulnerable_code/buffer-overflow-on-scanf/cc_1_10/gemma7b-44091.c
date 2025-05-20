//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct node {
    int data;
    struct node* next;
};

// Function to insert at the end
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Multiplayer game
int main() {
    // Initialize the linked list
    struct node* head = NULL;

    // Players take turns inserting nodes into the list
    int turn = 0;
    while (1) {
        // Get the player's input
        int data = 0;
        printf("Enter data: ");
        scanf("%d", &data);

        // Insert the node
        if (data != -1) {
            insertAtEnd(&head, data);
        } else {
            break;
        }

        // Print the list
        printList(head);

        // Change turns
        turn = (turn + 1) % 2;
    }

    // Print the final list
    printList(head);

    return 0;
}
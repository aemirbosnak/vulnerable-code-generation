//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to insert a node at the end of the list
void insert(Node** head, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
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

// Function to search for a value in the list
Node* search(Node* head, char value) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Insert some values into the list
    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');
    insert(&head, 'e');

    // Print the list
    printf("Original List:\n");
    printList(head);

    // Search for a value in the list
    Node* result = search(head, 'c');
    if (result!= NULL) {
        printf("Value '%c' found!\n", result->data);
    } else {
        printf("Value '%c' not found.\n", 'f');
    }

    return 0;
}
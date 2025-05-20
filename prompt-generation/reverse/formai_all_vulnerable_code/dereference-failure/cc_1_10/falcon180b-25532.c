//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void printList(Node* head);
int isListEmpty(Node* head);

// Main function
int main() {
    Node* head = NULL;

    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    addNode(&head, 20);

    printList(head);

    Node* temp = head;
    while (!isListEmpty(temp)) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}

// Function to add a node to the end of the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to check if the list is empty
int isListEmpty(Node* head) {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}
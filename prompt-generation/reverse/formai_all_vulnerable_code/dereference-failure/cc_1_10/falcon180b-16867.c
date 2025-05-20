//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the end of the list
void addNode(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to insert a new node at a specific position in the list
void insertNode(Node **head, int data, int position) {
    Node *newNode = createNode(data);
    Node *temp = *head;
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    for (int i = 1; i < position - 1 && temp!= NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node with the given data from the list
void deleteNode(Node **head, int data) {
    Node *temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data)
        temp = temp->next;
    if (temp == NULL)
        printf("Node not found\n");
}

// Function to reverse the list
void reverseList(Node **head) {
    Node *prev = NULL;
    Node *curr = *head;
    while (curr!= NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Function to print the list
void printList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    Node *head = NULL;
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    printList(head);
    insertNode(&head, 3, 2);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}
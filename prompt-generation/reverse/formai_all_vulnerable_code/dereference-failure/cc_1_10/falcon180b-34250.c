//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for each node in the linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void appendNode(Node** head, char data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Function to sort the linked list in ascending order
void sortList(Node** head) {
    Node* curr = *head;
    while (curr!= NULL && curr->next!= NULL) {
        char temp;
        if (curr->data > curr->next->data) {
            temp = curr->data;
            curr->data = curr->next->data;
            curr->next->data = temp;
        }
        curr = curr->next;
    }
}

int main() {
    Node* head = NULL;
    appendNode(&head, 'a');
    appendNode(&head, 'b');
    appendNode(&head, 'c');
    printList(head);
    reverseList(&head);
    printList(head);
    sortList(&head);
    printList(head);
    return 0;
}
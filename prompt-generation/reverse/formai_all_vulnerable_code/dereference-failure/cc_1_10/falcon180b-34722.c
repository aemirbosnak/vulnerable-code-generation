//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Thy kingdom is in peril! Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
    printf("A new knight, Sir %d, hath joined thy quest!\n", data);
}

// Function to add a node at the end of the list
void append(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* last = *headRef;

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        printf("The brave Sir %d hath joined thy quest!\n", data);
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = newNode;
    printf("Sir %d hath pledged his allegiance to thee!\n", data);
}

// Function to add a node after a given position
void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The noble Sir %d hath no predecessor!\n", data);
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    printf("The valiant Sir %d hath joined thy ranks!\n", data);
}

// Function to delete a node by key
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev;

    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        printf("The treacherous Sir %d hath been banished from thy kingdom!\n", key);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("Sir %d was not found in thy kingdom!\n", key);
    else {
        prev->next = temp->next;
        free(temp);
        printf("The disloyal Sir %d hath been exiled from thy realm!\n", key);
    }
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("The noble Sir %d is in thy service.\n", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    // Add nodes
    push(&head, 5);
    append(&head, 10);
    insertAfter(head->next, 7);

    // Print list
    printf("The knights in thy service are:\n");
    printList(head);

    // Delete nodes
    deleteNode(&head, 5);
    deleteNode(&head, 10);

    // Print list
    printf("\nThe remaining knights in thy service are:\n");
    printList(head);

    return 0;
}
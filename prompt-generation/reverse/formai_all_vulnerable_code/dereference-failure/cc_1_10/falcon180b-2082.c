//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void addNodeAtEnd(Node** headRef, int data);
void addNodeAtBeginning(Node** headRef, int data);
void addNodeAtPosition(Node** headRef, int data, int position);
void deleteNodeByValue(Node** headRef, int value);
void printList(Node* node);

int main() {
    Node* head = NULL;

    // Add nodes
    addNodeAtEnd(&head, 1);
    addNodeAtBeginning(&head, 2);
    addNodeAtEnd(&head, 3);
    addNodeAtBeginning(&head, 0);

    // Print list
    printList(head);

    // Delete node by value
    deleteNodeByValue(&head, 2);

    // Print list after deletion
    printList(head);

    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNodeAtEnd(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* last = *headRef;

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
    } else {
        while (last->next!= NULL)
            last = last->next;
        last->next = newNode;
    }
}

void addNodeAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data);

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
    } else {
        newNode->next = *headRef;
        *headRef = newNode;
    }
}

void addNodeAtPosition(Node** headRef, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = *headRef;
    int count = 1;

    if (position == 1) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        while (temp!= NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
            printf("Invalid position\n");
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteNodeByValue(Node** headRef, int value) {
    Node* temp = *headRef;

    if (temp!= NULL && temp->data == value) {
        *headRef = temp->next;
        free(temp);
    } else {
        while (temp!= NULL && temp->data!= value) {
            temp = temp->next;
        }
        if (temp == NULL)
            printf("Value not found\n");
        else {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
}

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
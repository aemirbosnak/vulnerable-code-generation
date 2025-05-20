//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
    printf("Node added at the beginning with data %d\n", newData);
}

// Function to add a node at the end of the list
void append(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        printf("Node added at the end with data %d\n", newData);
    } else {
        struct Node* last = *headRef;
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = newNode;
        printf("Node added at the end with data %d\n", newData);
    }
}

// Function to add a node after a given position
void addAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    printf("Node added after %d with data %d\n", prevNode->data, newData);
}

// Function to delete a node with given data
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        printf("Node deleted with data %d\n", key);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found with data %d\n", key);
        return;
    }
    struct Node* prevNode = temp->next;
    temp->next = prevNode->next;
    free(prevNode);
    printf("Node deleted with data %d\n", key);
}

// Function to display the list
void display(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    display(head);
    addAfter(head->next, 0);
    display(head);
    deleteNode(&head, 3);
    display(head);
    deleteNode(&head, 0);
    display(head);
    return 0;
}
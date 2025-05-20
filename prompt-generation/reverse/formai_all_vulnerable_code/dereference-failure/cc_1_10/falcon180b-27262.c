//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

// Function to create a new node with given data
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to add a node at the end of the list
void append(int data) {
    Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *last = head;
    while (last->next!= NULL)
        last = last->next;

    last->next = newNode;
}

// Function to add a node at a specific position in the list
void addAtPosition(int data, int pos) {
    Node *newNode = createNode(data);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp!= NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        printf("Invalid position\n");
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node with given data
void deleteNode(int data) {
    if (head == NULL)
        printf("List is empty\n");
    else if (head->data == data) {
        Node *temp = head;
        head = head->next;
        free(temp);
    } else {
        Node *temp = head;
        while (temp->next!= NULL && temp->next->data!= data)
            temp = temp->next;

        if (temp->next == NULL)
            printf("Element not found\n");
        else {
            Node *delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
        }
    }
}

// Function to display the list
void display() {
    Node *temp = head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);
    display();

    append(40);
    display();

    addAtPosition(15, 2);
    display();

    deleteNode(20);
    display();

    deleteNode(10);
    display();

    deleteNode(40);
    display();

    return 0;
}
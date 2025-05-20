//Falcon-180B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void addNode(Node** head, char* data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a node
Node* searchNode(Node* head, char* data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a node
Node* deleteNode(Node** head, char* data) {
    Node* temp = *head;
    if (temp!= NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return NULL;
    }
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return nodeToDelete;
}

int main() {
    Node* head = NULL;
    addNode(&head, "Hello");
    addNode(&head, "World");
    displayList(head);
    Node* nodeToDelete = searchNode(head, "Hello");
    if (nodeToDelete!= NULL) {
        deleteNode(&head, "Hello");
        displayList(head);
    }
    return 0;
}
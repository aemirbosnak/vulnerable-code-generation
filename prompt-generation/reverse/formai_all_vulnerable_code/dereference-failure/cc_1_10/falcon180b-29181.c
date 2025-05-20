//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
typedef struct node {
    char *name;
    int age;
    struct node *next;
} Node;

// Function to create a new node with the given name and age
Node* createNode(char *name, int age) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->name = (char*) malloc(strlen(name) + 1);
    if (newNode->name == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the end of the linked list
void addNode(Node **head, char *name, int age) {
    Node *newNode = createNode(name, age);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *lastNode = *head;
    while (lastNode->next!= NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to display the contents of the linked list
void displayList(Node *head) {
    printf("Name    Age\n");
    printf("---------------------\n");
    while (head!= NULL) {
        printf("%s   %d\n", head->name, head->age);
        head = head->next;
    }
}

int main() {
    Node *head = NULL;
    addNode(&head, "John", 25);
    addNode(&head, "Jane", 30);
    addNode(&head, "Bob", 20);
    displayList(head);
    return 0;
}
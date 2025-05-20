//Falcon-180B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char *data;
    struct node *next;
} Node;

Node *head = NULL;

void addNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void deleteNode(char *data) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node not found.\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp->data);
    free(temp);
    return;
}

void displayList() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
    return;
}

int main() {
    addNode("Hello");
    addNode("World");
    displayList();
    deleteNode("Hello");
    displayList();
    return 0;
}
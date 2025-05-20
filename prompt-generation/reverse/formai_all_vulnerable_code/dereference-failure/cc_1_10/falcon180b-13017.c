//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, char* data) {
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

void prepend(Node** head, char* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node** head, char* data) {
    Node* temp = *head;
    if (temp!= NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    Node* prev = temp->next;
    free(temp);
    temp = prev;
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    append(&head, "Hello");
    append(&head, "World");
    prepend(&head, "Hi");
    printList(head);
    deleteNode(&head, "Hi");
    printList(head);
    deleteNode(&head, "World");
    printList(head);
    deleteNode(&head, "Hello");
    printList(head);
    return 0;
}
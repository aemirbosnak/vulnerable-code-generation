//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    struct node *next;
} Node;

Node *head = NULL;

void addNode(char data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%c added to the list\n", data);
}

void deleteNode(char data) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%c not found in the list\n", data);
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("%c deleted from the list\n", data);
}

void printList() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    addNode('a');
    addNode('b');
    addNode('c');
    printList();
    deleteNode('b');
    printList();
    return 0;
}
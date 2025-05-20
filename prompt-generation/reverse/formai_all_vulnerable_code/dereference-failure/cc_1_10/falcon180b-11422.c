//Falcon-180B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    int size;
    struct node* next;
} Node;

Node* createNode(char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->size = strlen(str);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* str) {
    Node* newNode = createNode(str);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    addNode(&head, "Hello");
    addNode(&head, "World");
    addNode(&head, "How");
    addNode(&head, "are");
    addNode(&head, "you?");
    printList(head);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data;
    int size;
    struct Node* next;
} Node;

Node* createNode(char data, int size) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char data, int size) {
    Node* newNode = createNode(data, size);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c (%d)\n", temp->data, temp->size);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    char data;
    int size;

    printf("Enter data: ");
    scanf("%c", &data);
    printf("Enter size: ");
    scanf("%d", &size);

    addNode(&head, data, size);

    printf("The list contains: ");
    printList(head);

    return 0;
}
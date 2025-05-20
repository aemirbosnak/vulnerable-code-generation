//Falcon-180B DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void recursiveReverse(Node** head) {
    Node* curr = *head;
    Node* prev = NULL;
    Node* next = NULL;

    if (curr == NULL || curr->next == NULL) {
        return;
    }

    next = curr->next;
    curr->next = NULL;

    recursiveReverse(&next);

    curr->next = prev;
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    Node* head = NULL;

    for (int i = 0; i < size; i++) {
        int data = rand() % 100;
        addNode(&head, data);
    }

    printList(head);

    recursiveReverse(&head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}
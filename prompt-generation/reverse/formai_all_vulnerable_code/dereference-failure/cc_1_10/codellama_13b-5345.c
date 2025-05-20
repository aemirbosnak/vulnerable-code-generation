//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void pushFront(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void pushBack(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void insertAfter(struct Node **head, int data, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL || position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *curr = *head;
    for (int i = 0; i < position - 1; i++) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

void deleteNode(struct Node **head, int position) {
    if (*head == NULL || position < 0) {
        return;
    }
    if (position == 0) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node *curr = *head;
    for (int i = 0; i < position - 1; i++) {
        curr = curr->next;
    }
    struct Node *temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

int main() {
    struct Node *head = NULL;
    pushFront(&head, 1);
    pushFront(&head, 2);
    pushFront(&head, 3);
    printList(head);
    pushBack(&head, 4);
    pushBack(&head, 5);
    printList(head);
    insertAfter(&head, 6, 3);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    return 0;
}
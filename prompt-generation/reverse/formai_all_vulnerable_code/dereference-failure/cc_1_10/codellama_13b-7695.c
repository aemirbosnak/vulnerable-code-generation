//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: expert-level
/*
 * Linked list operations example program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void addNode(Node **head, int data) {
    Node *node = createNode(data);
    node->next = *head;
    *head = node;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteNode(Node **head, int data) {
    Node *node = *head;
    Node *prev = NULL;

    while (node != NULL && node->data != data) {
        prev = node;
        node = node->next;
    }

    if (node == NULL) {
        return;
    }

    if (prev == NULL) {
        *head = node->next;
    } else {
        prev->next = node->next;
    }

    free(node);
}

int main() {
    Node *head = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    printList(head);

    deleteNode(&head, 2);
    deleteNode(&head, 4);

    printList(head);

    return 0;
}
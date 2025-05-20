//Falcon-180B DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createLinkedList(int size, int value) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = value;
    head->next = NULL;

    Node* current = head;
    for (int i = 1; i < size; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i * 10;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }

    return head;
}

void printLinkedList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverseLinkedList(Node** headRef) {
    Node* prev = NULL;
    Node* current = *headRef;

    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *headRef = prev;
}

int main() {
    Node* head = createLinkedList(5, 50);
    printLinkedList(head);
    reverseLinkedList(&head);
    printLinkedList(head);

    return 0;
}
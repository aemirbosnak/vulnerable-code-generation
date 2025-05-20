//Falcon-180B DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void addNode(Node **head, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void deleteList(Node **head) {
    Node *temp = *head;
    while (temp!= NULL) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }
}

void reverseList(Node **head) {
    Node *prev = NULL;
    Node *curr = *head;
    while (curr!= NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    Node *head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    printf("Original List: ");
    printList(head);
    reverseList(&head);
    printf("\nReversed List: ");
    printList(head);
    deleteList(&head);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define struct for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node** head, int data) {
    Node* current = *head;
    Node* previous = NULL;

    if (current!= NULL && current->data == data) {
        *head = current->next;
        free(current);
        return;
    }

    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    previous->next = current->next;
    free(current);
}

void reverseList(Node** head) {
    Node* current = *head;
    Node* previous = NULL;
    Node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head = previous;
}

int main() {
    Node* head = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    printList(head);

    deleteNode(&head, 3);

    printList(head);

    reverseList(&head);

    printList(head);

    return 0;
}
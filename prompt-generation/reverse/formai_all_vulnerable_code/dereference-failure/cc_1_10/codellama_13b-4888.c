//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: multivariable
/*
* Linked list operations example program in a multivariable style
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void addNode(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(struct node **head, int data) {
    struct node *current = *head;
    struct node *previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Data not found in the list\n");
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void updateNode(struct node **head, int data, int newData) {
    struct node *current = *head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Data not found in the list\n");
        return;
    }
    current->data = newData;
}

int main() {
    struct node *head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    printList(head);
    deleteNode(&head, 20);
    printList(head);
    updateNode(&head, 30, 60);
    printList(head);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void createLinkedList(struct Node** head, int n) {
    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->data = 0;
    (*head)->next = NULL;
    struct Node* temp = *head;
    for (int i = 1; i < n; i++) {
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp = temp->next;
        temp->data = i;
        temp->next = NULL;
    }
}

void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    while (curr!= NULL) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    struct Node* head;
    createLinkedList(&head, 5);
    printf("Original linked list: ");
    printLinkedList(head);
    reverseLinkedList(&head);
    printf("Reversed linked list: ");
    printLinkedList(head);
    return 0;
}
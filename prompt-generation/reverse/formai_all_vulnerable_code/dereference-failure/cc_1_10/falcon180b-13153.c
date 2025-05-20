//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

Node* pop(Node** head) {
    Node* temp = *head;
    if (temp == NULL) {
        printf("List is empty\n");
        exit(0);
    }
    *head = temp->next;
    free(temp);
    return temp->next;
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    printList(head);
    head = pop(&head);
    printList(head);
    head = pop(&head);
    printList(head);
    head = pop(&head);
    printList(head);
    head = pop(&head);
    printList(head);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void addNode(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void displayList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);

    displayList(head);

    deleteNode(&head, 20);

    displayList(head);

    deleteNode(&head, 10);

    displayList(head);

    deleteNode(&head, 30);

    displayList(head);

    deleteNode(&head, 40);

    displayList(head);

    return 0;
}
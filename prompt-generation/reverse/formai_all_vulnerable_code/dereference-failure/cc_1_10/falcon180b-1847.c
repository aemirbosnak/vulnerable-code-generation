//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
}

void prependNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev;
    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void searchNode(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            printf("%d found\n", key);
        current = current->next;
    }
    if (current == NULL)
        printf("%d not found\n", key);
}

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    prependNode(&head, 5);
    prependNode(&head, 4);
    prependNode(&head, 3);
    prependNode(&head, 2);
    prependNode(&head, 1);
    printList(head);
    searchNode(head, 20);
    deleteNode(&head, 20);
    printList(head);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* removeNode(Node* head, int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Element not found\n");
        return head;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 5);
    printList(head);
    head = removeNode(head, 3);
    printList(head);
    head = removeNode(head, 5);
    printList(head);
    head = removeNode(head, 1);
    printList(head);
    head = removeNode(head, 4);
    printList(head);
    head = removeNode(head, 2);
    printList(head);
    return 0;
}
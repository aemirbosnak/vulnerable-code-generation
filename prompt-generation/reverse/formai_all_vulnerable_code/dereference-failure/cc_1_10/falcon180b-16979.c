//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* appendNode(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* prependNode(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* deleteNode(Node* head, int data) {
    Node* temp = head;
    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    Node* next = temp->next;
    free(temp);
    temp = next;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = prependNode(head, 10);
    head = appendNode(head, 20);
    head = appendNode(head, 30);
    head = prependNode(head, 5);
    head = deleteNode(head, 10);
    printList(head);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

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

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = NULL;
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return head;
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
        printf("Element not found\n");
        return head;
    }
    Node* next = temp->next;
    free(temp);
    return next;
}

Node* searchNode(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return NULL;
    }
    return temp;
}

void printList(Node* head) {
    Node* temp = head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = insertNode(head, 10);
    printList(head);
    head = insertNode(head, 20);
    printList(head);
    head = insertNode(head, 30);
    printList(head);
    head = deleteNode(head, 20);
    printList(head);
    Node* foundNode = searchNode(head, 30);
    if (foundNode!= NULL) {
        printf("Found node with data %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }
    return 0;
}
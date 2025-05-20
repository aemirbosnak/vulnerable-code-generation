//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* next;
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
    Node* nextNode = temp->next;
    free(temp);
    temp = nextNode;
    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchList(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return TRUE;
        }
        temp = temp->next;
    }
    return FALSE;
}

int main() {
    Node* head = NULL;
    head = insertNode(head, 10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);
    head = insertNode(head, 40);
    head = insertNode(head, 50);
    displayList(head);
    head = deleteNode(head, 20);
    displayList(head);
    if (searchList(head, 30)) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }
    return 0;
}
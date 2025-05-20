//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: happy
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
    if (head == NULL) {
        return newNode;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* prependNode(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (head == NULL) {
        return newNode;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

Node* insertNode(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (head == NULL) {
        return newNode;
    }
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    for (int i = 0; i < position - 1; i++) {
        if (temp->next!= NULL) {
            temp = temp->next;
        } else {
            return head;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* removeNode(Node* head, int data) {
    Node* temp = head;
    if (head == NULL) {
        return head;
    }
    if (temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        return head;
    }
    Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    head = appendNode(head, 10);
    head = appendNode(head, 20);
    head = appendNode(head, 30);
    head = prependNode(head, 5);
    head = prependNode(head, 4);
    head = prependNode(head, 3);
    head = insertNode(head, 15, 2);
    head = removeNode(head, 20);
    displayList(head);
    return 0;
}
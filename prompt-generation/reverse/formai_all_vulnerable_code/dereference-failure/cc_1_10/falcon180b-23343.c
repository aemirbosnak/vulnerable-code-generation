//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;
    if (head!= NULL && head->data == data) {
        head = head->next;
        free(temp);
        return head;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

Node* searchNode(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
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
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);
    printf("Original List:\n");
    printList(head);
    head = deleteNode(head, 3);
    printf("List after deleting 3:\n");
    printList(head);
    Node* found = searchNode(head, 4);
    if (found!= NULL) {
        printf("Found %d in the list.\n", found->data);
    } else {
        printf("4 not found in the list.\n");
    }
    return 0;
}
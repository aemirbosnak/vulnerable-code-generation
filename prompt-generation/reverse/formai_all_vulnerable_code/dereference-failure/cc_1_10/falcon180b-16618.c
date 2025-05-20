//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
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

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    Node* temp = head;
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int key) {
    Node* temp = head;
    if (temp!= NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }
    if (temp == NULL)
        return head;
    Node* t = temp->next;
    temp->next = t->next;
    free(t);
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

int main() {
    Node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);
    displayList(head);
    head = deleteNode(head, 20);
    displayList(head);
    return 0;
}
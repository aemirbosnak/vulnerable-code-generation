//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void addElement(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList() {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteElement(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    Node* temp = head;
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element not found.\n");
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void reverseList() {
    Node* prev = NULL;
    Node* current = head;

    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

int main() {
    addElement(1);
    addElement(2);
    addElement(3);
    addElement(4);
    addElement(5);

    printf("Original List:\n");
    printList();

    reverseList();

    printf("Reversed List:\n");
    printList();

    deleteElement(3);

    printf("List after deleting 3:\n");
    printList();

    return 0;
}
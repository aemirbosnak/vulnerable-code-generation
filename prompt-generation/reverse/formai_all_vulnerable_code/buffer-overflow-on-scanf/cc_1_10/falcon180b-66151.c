//Falcon-180B DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void addNode(int data) {
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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Element not found!\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

int main() {
    int choice, data;

    do {
        printf("1. Add element\n2. Print list\n3. Delete element\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                addNode(data);
                break;
            case 2:
                printList();
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}
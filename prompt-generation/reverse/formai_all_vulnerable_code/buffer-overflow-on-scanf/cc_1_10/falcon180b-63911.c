//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node** headRef, int data) {
    node* newNode = createNode(data);
    node* temp = *headRef;

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }

    while (temp!= NULL && temp->data < data) {
        temp = temp->next;
    }

    newNode->next = temp;
    temp = temp!= NULL? temp->next : NULL;
    newNode->next = temp;
    *headRef = newNode;
}

void deleteNode(node** headRef, int data) {
    node* temp = *headRef;
    node* prev = NULL;

    if (temp == NULL || temp->data == data) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void searchElement(node* head, int key) {
    node* current = head;
    while (current!= NULL) {
        if (current->data == key) {
            printf("Element found!\n");
            return;
        }
        current = current->next;
    }
    printf("Element not found.\n");
}

int main() {
    node* head = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert element\n2. Delete element\n3. Search element\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            searchElement(head, data);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
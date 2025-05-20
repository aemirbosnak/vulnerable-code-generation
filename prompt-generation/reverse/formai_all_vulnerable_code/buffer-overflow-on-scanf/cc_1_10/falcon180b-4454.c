//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* last = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void prependNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void searchNode(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key) {
            printf("Node found!\n");
            return;
        }
        current = current->next;
    }
    printf("Node not found.\n");
}

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice = 0, data, key;
    while (choice!= 5) {
        printf("1. Append node\n2. Prepend node\n3. Delete node\n4. Search node\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                appendNode(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                prependNode(&head, data);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                searchNode(head, key);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
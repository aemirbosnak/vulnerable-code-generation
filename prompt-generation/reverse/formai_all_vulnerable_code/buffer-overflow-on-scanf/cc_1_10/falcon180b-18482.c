//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int searchElement(Node *head, int key) {
    Node *temp = head;
    while (temp!= NULL) {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
    return;
}

void deleteNode(Node **head, int key) {
    Node *temp = *head, *prev;
    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void reverseList(Node **head) {
    Node *prev, *curr, *next;
    prev = NULL;
    curr = *head;
    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    Node *head = NULL;
    int choice, data, key;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Print\n5. Reverse\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
        case 2:
            printf("Enter element to delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;
        case 3:
            printf("Enter element to search: ");
            scanf("%d", &key);
            if (searchElement(head, key))
                printf("%d found\n", key);
            else
                printf("%d not found\n", key);
            break;
        case 4:
            printList(head);
            break;
        case 5:
            reverseList(&head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
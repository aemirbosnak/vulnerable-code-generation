//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));

    Node* head = NULL;

    for (int i = 0; i < SIZE; i++) {
        int data = rand() % 100;
        insertNode(&head, data);
    }

    printf("Original list:\n");
    printList(head);

    int searchData;
    printf("\nEnter a value to search: ");
    scanf("%d", &searchData);

    Node* foundNode = head;
    while (foundNode!= NULL) {
        if (foundNode->data == searchData) {
            printf("\nValue found at position %d\n", (int)((foundNode - head) + 1));
            break;
        }
        foundNode = foundNode->next;
    }

    if (foundNode == NULL)
        printf("\nValue not found\n");

    int deleteData;
    printf("\nEnter a value to delete: ");
    scanf("%d", &deleteData);

    deleteNode(&head, deleteData);

    printf("\nList after deleting %d:\n", deleteData);
    printList(head);

    return 0;
}
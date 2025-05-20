//Falcon-180B DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 1000

typedef struct node {
    int data;
    int priority;
    struct node* next;
} Node;

Node* createNode(int data, int priority) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data, int priority) {
    Node* newNode = createNode(data, priority);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* currNode = *head;
    while (currNode->next!= NULL && currNode->next->priority > priority) {
        currNode = currNode->next;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
}

void delete(Node** head, int data) {
    Node* currNode = *head;
    while (currNode!= NULL && currNode->data!= data) {
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        printf("Element not found\n");
        return;
    }
    *head = currNode->next;
    free(currNode);
}

void display(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Node* head = NULL;
    int choice, data, priority;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            insert(&head, data, priority);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            delete(&head, data);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
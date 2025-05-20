//Falcon-180B DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

void init(Node** head) {
    *head = NULL;
}

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

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteList(Node** head) {
    Node* temp = *head;
    while (temp!= NULL) {
        Node* nextTemp = temp->next;
        free(temp);
        temp = nextTemp;
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;
    init(&head);

    int choice, data;
    do {
        printf("\n");
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            addNode(&head, data);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            printf("Exiting...\n");
            deleteList(&head);
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}
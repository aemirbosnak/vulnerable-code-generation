//Falcon-180B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        Node* nextTemp = temp->next;
        free(temp);
        temp = nextTemp;
    }
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
    int choice, data;
    char str[MAX_SIZE];

    while (1) {
        printf("\n1. Add element\n2. Print list\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            head = createNode(data);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
        getchar();
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(node* head, int data) {
    node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void printList(node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int choice, data;

    while (1) {
        printf("1. Add node\n2. Print list\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(head, data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
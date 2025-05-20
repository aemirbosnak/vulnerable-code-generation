//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* addNode(struct node* head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp = head;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int choice, data;

    while (1) {
        printf("1. Add node\n2. Print list\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = addNode(head, data);
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
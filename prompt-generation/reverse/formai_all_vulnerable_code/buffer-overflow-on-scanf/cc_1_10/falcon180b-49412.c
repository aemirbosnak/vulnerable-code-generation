//Falcon-180B DATASET v1.0 Category: Recursive ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void addNode(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

bool isEmpty(Node* head) {
    return head == NULL;
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("1. Add node\n2. Print list\n3. Reverse list\n4. Exit\n");
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
                reverseList(&head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (true);

    return 0;
}
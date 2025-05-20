//Falcon-180B DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverseList(Node** headRef) {
    Node* prev = NULL;
    Node* current = *headRef;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

void recursiveReverse(Node** headRef, int depth) {
    if (depth == 0 || *headRef == NULL || (*headRef)->next == NULL) {
        return;
    }
    Node* rest = (*headRef)->next;
    (*headRef)->next = NULL;
    recursiveReverse(&rest, depth - 1);
    Node* last = rest;
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = *headRef;
    *headRef = rest;
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("1. Add element\n");
        printf("2. Print list\n");
        printf("3. Reverse list\n");
        printf("4. Recursive reverse list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                head = createNode(data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                reverseList(&head);
                printf("List reversed\n");
                break;
            case 4:
                printf("Enter the depth: ");
                scanf("%d", &data);
                recursiveReverse(&head, data);
                printf("List recursively reversed\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}
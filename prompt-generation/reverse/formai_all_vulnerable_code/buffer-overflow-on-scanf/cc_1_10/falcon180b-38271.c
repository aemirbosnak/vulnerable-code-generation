//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int searchList(struct Node* head, int searchData) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == searchData) {
            printf("Element found\n");
            return 1;
        }
        current = current->next;
    }
    printf("Element not found\n");
    return 0;
}

int main() {
    struct Node* head = NULL;
    int choice, searchData;

    do {
        printf("1. Add element\n");
        printf("2. Print list\n");
        printf("3. Search element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &searchData);
                addNode(&head, searchData);
                break;
            case 2:
                printf("List: ");
                printList(head);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &searchData);
                searchList(head, searchData);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}
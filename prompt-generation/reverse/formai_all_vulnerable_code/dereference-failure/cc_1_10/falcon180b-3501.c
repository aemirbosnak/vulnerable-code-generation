//Falcon-180B DATASET v1.0 Category: Recursive ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} LinkedList;

void printList(LinkedList* head) {
    LinkedList* current = head;
    while (current!= NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

LinkedList* createList(int size) {
    LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
    strcpy(head->data, "0");
    head->next = NULL;
    return head;
}

void addNode(LinkedList* head, int index) {
    LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
    strcpy(newNode->data, "");
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    LinkedList* current = head;
    while (current->next!= NULL && index > 0) {
        current = current->next;
        index--;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(LinkedList* head, int index) {
    if (head == NULL) {
        return;
    }

    if (index == 0) {
        head = head->next;
        return;
    }

    LinkedList* current = head;
    while (current->next!= NULL && index > 0) {
        current = current->next;
        index--;
    }

    if (current->next == NULL) {
        return;
    }

    current->next = current->next->next;
}

int main() {
    LinkedList* head = createList(MAX_SIZE);
    int choice, index, size;

    do {
        printf("1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the index: ");
                scanf("%d", &index);
                printf("Enter the size of the node: ");
                scanf("%d", &size);
                addNode(head, index);
                break;
            case 2:
                printf("Enter the index: ");
                scanf("%d", &index);
                deleteNode(head, index);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}
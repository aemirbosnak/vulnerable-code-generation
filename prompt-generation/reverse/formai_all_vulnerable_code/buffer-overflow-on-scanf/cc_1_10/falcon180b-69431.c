//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("\nLinked List Menu:\n");
        printf("1. Add Node\n");
        printf("2. Print List\n");
        printf("3. Reverse List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("List after adding nodes:\n");
                printList(head);
                break;
            case 3:
                reverseList(&head);
                printf("List after reversing:\n");
                printList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}
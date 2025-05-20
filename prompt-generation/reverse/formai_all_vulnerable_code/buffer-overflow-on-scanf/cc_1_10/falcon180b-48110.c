//Falcon-180B DATASET v1.0 Category: Educational ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} Node;

void addToTail(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node* current = *head;
    if (*head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (current->next!= NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void deleteFromHead(Node** head) {
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Add element to tail\n");
        printf("2. Delete element from head\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &data);
                addToTail(&head, data);
                break;
            case 2:
                deleteFromHead(&head);
                break;
            case 3:
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
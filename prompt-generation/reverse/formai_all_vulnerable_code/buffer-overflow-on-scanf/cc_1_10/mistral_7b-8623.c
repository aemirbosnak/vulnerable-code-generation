//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

typedef struct Node {
    char data[SIZE];
    struct Node *next;
} Node;

void printList(Node *head) {
    Node *current = head;
    int i = 0;

    printf("\nLinked List State:");

    while (current != NULL) {
        printf("\n[%d] %s ->", i, current->data);
        current = current->next;
        i++;
    }

    printf("NULL");
}

void addElement(Node **head, char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    strcpy(newNode->data, data);
    newNode->next = *head;
    *head = newNode;
}

int main() {
    Node *head = NULL;
    char input[SIZE];
    int choice;

    while (1) {
        printList(head);
        printf("\n1. Add element\n2. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the data to add: ");
            scanf("%s", input);
            addElement(&head, input);
        } else {
            break;
        }
    }

    return 0;
}
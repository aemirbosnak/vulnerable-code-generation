//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *head) {
    printf("[");
    while (head) {
        printf("%d", head->data);
        head = head->next;
        if (head) printf(", ");
    }
    printf("]\n");
}

void pushNode(struct Node **head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void insertNode(struct Node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Error: The previous node cannot be NULL.\n");
        return;
    }

    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteNode(struct Node **head, int key) {
    struct Node *temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Error: The key to be deleted was not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct Node *head = NULL;
    int option, value, prev, key;

    printf("Welcome to the Cyberpunk Linked List Operations!\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Print the list\n");
        printf("2. Push a node to the beginning\n");
        printf("3. Insert a node after a specific node\n");
        printf("4. Delete a node\n");
        printf("5. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printList(head);
                break;
            case 2:
                printf("Enter a value: ");
                scanf("%d", &value);
                pushNode(&head, value);
                break;
            case 3:
                printf("Enter the previous node's value: ");
                scanf("%d", &prev);
                printf("Enter a value: ");
                scanf("%d", &value);
                insertNode(head->next, value);
                break;
            case 4:
                printf("Enter a key to be deleted: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    } while (1);

    return 0;
}
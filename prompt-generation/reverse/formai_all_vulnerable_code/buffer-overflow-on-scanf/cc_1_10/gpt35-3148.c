//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node *next;
} Node;

Node* createNode(char email[]);
void insertNode(Node **headPtr, char email[]);
void printList(Node **headPtr);
void deleteList(Node **headPtr);

int main() {
    Node *head = NULL;
    char email[50];

    printf("Welcome to the Mailing List Manager!\n");
    printf("Enter 'exit' to quit.\n");

    while (1) {
        printf("Enter email: ");
        scanf("%s", email);
        if (strcmp(email, "exit") == 0) {
            break;
        }
        insertNode(&head, email);
        printf("%s has been added to the mailing list.\n", email);
    }

    printf("Mailing list:\n");
    printList(&head);

    deleteList(&head);

    printf("Thank you for using the Mailing List Manager!\n");

    return 0;
}

Node* createNode(char email[]) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **headPtr, char email[]) {
    Node *newNode = createNode(email);
    if (*headPtr == NULL) {
        *headPtr = newNode;
    } else {
        Node *current = *headPtr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node **headPtr) {
    Node *current = *headPtr;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void deleteList(Node **headPtr) {
    Node *current = *headPtr;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *headPtr = NULL;
}
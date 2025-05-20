//Falcon-180B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} Node;

Node *createNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node **head, char *data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *currNode = *head;
    while (currNode->next!= NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

void printList(Node *head) {
    Node *currNode = head;
    while (currNode!= NULL) {
        printf("%s -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    char input[100];
    while (1) {
        printf("Enter data to add (or type 'exit' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        addNode(&head, input);
    }
    printf("Linked list:\n");
    printList(head);
    return 0;
}
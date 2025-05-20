//FormAI DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void addNode(Node **head, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNode(Node **head, int key) {
    Node *temp = *head;
    Node *prev;
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
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    Node *head = NULL;

    printf("Welcome to the post-apocalyptic linked list operations program!\n");
    printf("You are the last survivor in a world overrun by machines.\n");
    printf("You must use your skills to manage and manipulate the last remaining data structures.\n");
    printf("Use the following commands to interact with the linked list:\n");

    while (1) {
        printf("add <value> - adds a node to the beginning of the list with the given value\n");
        printf("delete <value> - removes the first node with the given value from the list\n");
        printf("print - prints the values in the list\n");
        printf("exit - exits the program\n");

        char input[10];
        int num;

        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            scanf("%d", &num);
            addNode(&head, num);
            printf("Added node with value %d\n", num);
        } else if (strcmp(input, "delete") == 0) {
            scanf("%d", &num);
            deleteNode(&head, num);
        } else if (strcmp(input, "print") == 0) {
            printList(head);
        } else if (strcmp(input, "exit") == 0) {
            printf("Goodbye, survivor.\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
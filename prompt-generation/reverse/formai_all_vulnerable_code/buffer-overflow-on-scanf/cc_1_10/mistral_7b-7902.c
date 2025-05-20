//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, char data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search(Node* head, char key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Data '%c' found at position %d\n", key, 1 + (int) (sizeof(Node*) * (char) (temp - head)));
            return 1;
        }
        temp = temp->next;
    }
    printf("Data '%c' not found\n", key);
    return 0;
}

int main() {
    Node* head = NULL;
    char input[MAX_SIZE];
    char command;
    char key;

    printf("Welcome to the Cybernetic Search Engine v1.0\n");
    printf("----------------------------------------------\n");

    while (1) {
        printf("\nAvailable commands:\n");
        printf("  i - Insert data at the beginning of the list\n");
        printf("  s - Search for data in the list\n");
        printf("  q - Quit the program\n");
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'i':
                printf("Enter data: ");
                scanf(" %s", input);
                head = insertAtBeginning(head, input[0]);
                break;

            case 's':
                printf("Enter data to search: ");
                scanf(" %c", &key);
                search(head, key);
                break;

            case 'q':
                free(head);
                exit(0);

            default:
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}
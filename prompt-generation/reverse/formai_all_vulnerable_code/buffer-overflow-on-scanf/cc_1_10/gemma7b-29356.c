//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void display(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    Node* head = NULL;

    // Multiplayer interaction
    char command;
    int data;

    while (1) {
        printf("Enter command (insert/display/exit): ");
        scanf("%c", &command);

        switch (command) {
            case 'i':
                printf("Enter data: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 'd':
                display(head);
                break;
            case 'e':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}
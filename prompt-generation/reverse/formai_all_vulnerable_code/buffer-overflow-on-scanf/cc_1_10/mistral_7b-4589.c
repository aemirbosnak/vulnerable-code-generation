//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int gold;
} Knight;

typedef struct Node {
    Knight data;
    struct Node *next;
} Node;

Node* createNode(Knight knight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = knight;
    newNode->next = NULL;
    return newNode;
}

void addKnight(Node** head, Knight knight) {
    Node* newNode = createNode(knight);
    newNode->next = *head;
    *head = newNode;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s has %d gold.\n", current->data.name, current->data.gold);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    Knight newKnight;

    while (1) {
        printf("Enter Knight's name (or 'quit' to exit): ");
        scanf("%s", newKnight.name);
        if (strcmp(newKnight.name, "quit") == 0) {
            break;
        }

        printf("Enter Knight's gold: ");
        scanf("%d", &newKnight.gold);

        addKnight(&head, newKnight);
    }

    printf("\nKnight's records:\n");
    displayList(head);

    return 0;
}
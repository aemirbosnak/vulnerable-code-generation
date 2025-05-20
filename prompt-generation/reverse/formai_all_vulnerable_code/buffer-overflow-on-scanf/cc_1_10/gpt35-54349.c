//FormAI DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char email[50];
    struct Node* next;
};

struct List {
    struct Node* head;
};

void initializeList(struct List* list) {
    list->head = NULL;
}

void appendEmail(struct List* list, char email[]) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(struct List* list) {
    printf("Mailing list:\n");
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    struct List list;
    initializeList(&list);

    char email[50];
    printf("Enter email (or \"quit\" to exit):\n");

    while (1) {
        scanf("%s", email);

        if (strcmp(email, "quit") == 0) {
            break;
        }

        appendEmail(&list, email);
        printf("Enter email (or \"quit\" to exit):\n");
    }

    printList(&list);

    return 0;
}
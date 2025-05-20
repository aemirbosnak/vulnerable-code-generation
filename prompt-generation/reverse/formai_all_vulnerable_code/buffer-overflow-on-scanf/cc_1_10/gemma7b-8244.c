//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 100

typedef struct Node {
    char name[MAX_INDEX];
    struct Node* next;
} Node;

Node* insert(Node* head, char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int search(Node* head, char name[]) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    Node* head = NULL;

    // Multiplayer interaction
    char name[MAX_INDEX];
    printf("Enter name: ");
    scanf("%s", name);

    insert(head, name);

    printf("Enter name to search: ");
    scanf("%s", name);

    if (search(head, name) == 1) {
        printf("Name found.\n");
    } else {
        printf("Name not found.\n");
    }

    return 0;
}
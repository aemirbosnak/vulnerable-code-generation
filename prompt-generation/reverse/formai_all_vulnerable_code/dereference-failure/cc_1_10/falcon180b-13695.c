//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char data[MAX_SIZE];
    int size;
    struct node *next;
} Node;

Node *head = NULL;

void insert(char *key) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->data, key);
    new_node->size = strlen(key);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node *current = head;
    while (current->next!= NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void search(char *key) {
    Node *current = head;

    while (current!= NULL) {
        if (strcmp(current->data, key) == 0) {
            printf("Key found!\n");
            return;
        }

        current = current->next;
    }

    printf("Key not found.\n");
}

int main() {
    head = NULL;

    insert("apple");
    insert("banana");
    insert("cherry");

    search("apple");
    search("banana");
    search("cherry");
    search("orange");

    return 0;
}
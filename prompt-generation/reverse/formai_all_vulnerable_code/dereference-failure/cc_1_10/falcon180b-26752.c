//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_VALUES 50

typedef struct node {
    char *key;
    int *value;
    struct node *next;
} Node;

Node *root = NULL;

void insert(char *key, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = (int*)malloc(MAX_VALUES * sizeof(int));
    new_node->value[0] = value;
    new_node->next = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        Node *curr_node = root;
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

void search(char *key) {
    Node *curr_node = root;
    while (curr_node!= NULL) {
        if (strcmp(curr_node->key, key) == 0) {
            printf("Found key %s with value %d\n", key, curr_node->value[0]);
            return;
        }
        curr_node = curr_node->next;
    }
    printf("Key %s not found\n", key);
}

int main() {
    root = NULL;
    insert("John", 25);
    insert("Jane", 30);
    insert("Bob", 20);
    search("Jane");
    search("Bob");
    search("Alice");
    return 0;
}
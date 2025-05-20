//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100001

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *hash_table[TABLE_SIZE];

int hash_func(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash_func(key);
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int search(int key) {
    int index = hash_func(key);
    Node *current = hash_table[index];
    while (current != NULL) {
        if (current->key == key)
            return 1;
        current = current->next;
    }
    return 0;
}

int main() {
    int n, i, key;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    int queries;
    scanf("%d", &queries);
    for (i = 0; i < queries; i++) {
        scanf("%d", &key);
        if (search(key) == 1)
            printf("Present\n");
        else
            printf("Absent\n");
    }
    return 0;
}
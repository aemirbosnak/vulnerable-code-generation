//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 512

typedef struct HashNode {
    char *key;
    int data;
    struct HashNode *next;
} HashNode;

HashNode *hash_insert(HashNode *head, char *key, int data) {
    int hash_index = hash(key);
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
    new_node->key = strdup(key);
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        HashNode *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    return head;
}

int hash(char *key) {
    int i = 0;
    int hash_value = 0;
    while (key[i] != '\0') {
        hash_value = (hash_value * 33) + key[i];
        i++;
    }

    return hash_value % HASH_SIZE;
}

int main() {
    HashNode *head = NULL;
    head = hash_insert(head, "John Doe", 12);
    head = hash_insert(head, "Jane Doe", 13);
    head = hash_insert(head, "Jack Doe", 14);

    HashNode *current = head;
    while (current) {
        printf("%s: %d\n", current->key, current->data);
        current = current->next;
    }

    return 0;
}
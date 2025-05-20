//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 1024

typedef struct HashNode {
    char *key;
    struct HashNode *next;
} HashNode;

HashNode **hash_table = NULL;

int hash(char *str) {
    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value = (hash_value * 33) + str[i];
    }
    return hash_value % HASH_SIZE;
}

void insert(char *str) {
    int index = hash(str);
    HashNode *node = malloc(sizeof(HashNode));
    node->key = strdup(str);
    node->next = NULL;

    if (hash_table == NULL) {
        hash_table = node;
    } else {
        HashNode *current = hash_table;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }
}

int main() {
    insert("John Doe");
    insert("Jane Doe");
    insert("Bill Smith");

    HashNode *current = hash_table;
    while (current) {
        printf("%s\n", current->key);
        current = current->next;
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *key;
    int value;
} pair_t;

pair_t *hash_table;

int hash(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return sum % MAX_SIZE;
}

void init() {
    hash_table = (pair_t *)malloc(MAX_SIZE * sizeof(pair_t));
    memset(hash_table, 0, MAX_SIZE * sizeof(pair_t));
}

int insert(char *key, int value) {
    int index = hash(key);
    pair_t *pair = &hash_table[index];
    while (pair->key!= NULL && strcmp(key, pair->key)!= 0) {
        pair++;
    }
    if (pair->key == NULL) {
        pair->key = strdup(key);
        pair->value = value;
        return 1;
    } else {
        pair->value = value;
        return 0;
    }
}

int search(char *key) {
    int index = hash(key);
    pair_t *pair = &hash_table[index];
    while (pair->key!= NULL && strcmp(key, pair->key)!= 0) {
        pair++;
    }
    if (pair->key == NULL) {
        return -1;
    } else {
        return pair->value;
    }
}

void destroy() {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        pair_t *pair = &hash_table[i];
        if (pair->key!= NULL) {
            free(pair->key);
            pair->key = NULL;
        }
    }
    free(hash_table);
}

int main() {
    init();
    insert("apple", 10);
    insert("banana", 20);
    insert("cherry", 30);
    printf("%d\n", search("apple"));
    printf("%d\n", search("banana"));
    printf("%d\n", search("cherry"));
    printf("%d\n", search("grape"));
    destroy();
    return 0;
}
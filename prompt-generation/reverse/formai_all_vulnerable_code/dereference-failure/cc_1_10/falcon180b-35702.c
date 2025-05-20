//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* key;
    int value;
} pair;

typedef struct {
    pair* data;
    int size;
} table;

void init(table* t) {
    t->data = (pair*) malloc(MAX_SIZE * sizeof(pair));
    t->size = 0;
}

int hash(char* key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return sum % MAX_SIZE;
}

void insert(table* t, char* key, int value) {
    int index = hash(key);
    while (t->data[index].key!= NULL) {
        index = (index + 1) % MAX_SIZE;
    }
    t->data[index].key = strdup(key);
    t->data[index].value = value;
    t->size++;
}

int search(table* t, char* key) {
    int index = hash(key);
    while (t->data[index].key!= NULL) {
        if (strcmp(t->data[index].key, key) == 0) {
            return t->data[index].value;
        }
        index = (index + 1) % MAX_SIZE;
    }
    return -1;
}

int main() {
    table t;
    init(&t);
    insert(&t, "apple", 1);
    insert(&t, "banana", 2);
    insert(&t, "cherry", 3);
    int value = search(&t, "banana");
    printf("%d\n", value);
    return 0;
}
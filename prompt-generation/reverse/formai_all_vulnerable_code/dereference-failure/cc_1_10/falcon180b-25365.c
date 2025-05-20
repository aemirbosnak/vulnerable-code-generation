//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_NUM_KEYS 1000
#define MAX_INDEX_NAME_LEN 50

typedef struct {
    char *key;
    char *value;
} KeyValue;

typedef struct {
    char *name;
    int num_keys;
    KeyValue *keys;
} Index;

Index *create_index(char *index_name) {
    Index *index = (Index *) malloc(sizeof(Index));
    strncpy(index->name, index_name, MAX_INDEX_NAME_LEN);
    index->num_keys = 0;
    index->keys = NULL;
    return index;
}

void destroy_index(Index *index) {
    int i;
    for (i = 0; i < index->num_keys; i++) {
        free(index->keys[i].key);
        free(index->keys[i].value);
    }
    free(index->keys);
    free(index);
}

void add_key(Index *index, char *key, char *value) {
    if (index->num_keys >= MAX_NUM_KEYS) {
        printf("Error: Index is full.\n");
        return;
    }
    KeyValue *new_key = (KeyValue *) malloc(sizeof(KeyValue));
    strncpy(new_key->key, key, MAX_KEY_LEN);
    strncpy(new_key->value, value, MAX_VALUE_LEN);
    index->keys = (KeyValue *) realloc(index->keys, sizeof(KeyValue) * (index->num_keys + 1));
    index->keys[index->num_keys] = *new_key;
    index->num_keys++;
}

void print_keys(Index *index) {
    int i;
    for (i = 0; i < index->num_keys; i++) {
        printf("%s -> %s\n", index->keys[i].key, index->keys[i].value);
    }
}

int main() {
    Index *index = create_index("my_index");
    add_key(index, "apple", "red");
    add_key(index, "banana", "yellow");
    add_key(index, "cherry", "red");
    print_keys(index);
    destroy_index(index);
    return 0;
}
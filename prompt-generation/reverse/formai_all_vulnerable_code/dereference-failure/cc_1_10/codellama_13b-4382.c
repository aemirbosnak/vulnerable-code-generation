//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: artistic
// artistic_database_indexing.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 100

struct db_entry {
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];
};

struct db_index {
    struct db_entry *entries[MAX_KEY_LEN];
};

struct db_index *create_index() {
    struct db_index *idx = malloc(sizeof(struct db_index));
    for (int i = 0; i < MAX_KEY_LEN; i++) {
        idx->entries[i] = NULL;
    }
    return idx;
}

void insert_entry(struct db_index *idx, char *key, char *val) {
    int key_len = strlen(key);
    struct db_entry *new_entry = malloc(sizeof(struct db_entry));
    strcpy(new_entry->key, key);
    strcpy(new_entry->val, val);
    for (int i = 0; i < key_len; i++) {
        if (idx->entries[i] == NULL) {
            idx->entries[i] = new_entry;
            break;
        }
    }
}

char *get_entry(struct db_index *idx, char *key) {
    int key_len = strlen(key);
    for (int i = 0; i < key_len; i++) {
        if (idx->entries[i] != NULL && strcmp(idx->entries[i]->key, key) == 0) {
            return idx->entries[i]->val;
        }
    }
    return NULL;
}

int main() {
    struct db_index *idx = create_index();
    insert_entry(idx, "name", "Alice");
    insert_entry(idx, "age", "25");
    insert_entry(idx, "city", "New York");
    printf("name: %s\n", get_entry(idx, "name"));
    printf("age: %s\n", get_entry(idx, "age"));
    printf("city: %s\n", get_entry(idx, "city"));
    return 0;
}
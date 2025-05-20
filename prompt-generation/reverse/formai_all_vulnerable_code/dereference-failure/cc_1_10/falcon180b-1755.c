//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    int num_keys;
    KeyValuePair *keys;
} Database;

void create_database(Database *db) {
    db->num_keys = 0;
    db->keys = NULL;
}

void destroy_database(Database *db) {
    int i;
    for (i = 0; i < db->num_keys; i++) {
        free(db->keys[i].key);
        free(db->keys[i].value);
    }
    free(db->keys);
    db->num_keys = 0;
}

void add_key_value_pair(Database *db, char *key, char *value) {
    if (db->num_keys >= MAX_NUM_KEYS) {
        printf("Error: Max number of keys reached\n");
        return;
    }
    KeyValuePair *new_key_value_pair = malloc(sizeof(KeyValuePair));
    new_key_value_pair->key = strdup(key);
    new_key_value_pair->value = strdup(value);
    db->keys = realloc(db->keys, sizeof(KeyValuePair) * (db->num_keys + 1));
    db->keys[db->num_keys] = *new_key_value_pair;
    db->num_keys++;
}

int search_key(Database *db, char *key) {
    int i;
    for (i = 0; i < db->num_keys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

char *get_value_by_key(Database *db, char *key) {
    int index = search_key(db, key);
    if (index == -1) {
        return NULL;
    }
    return db->keys[index].value;
}

int main() {
    Database db;
    create_database(&db);
    add_key_value_pair(&db, "name", "John");
    add_key_value_pair(&db, "age", "30");
    char *value = get_value_by_key(&db, "name");
    if (value!= NULL) {
        printf("Name: %s\n", value);
    } else {
        printf("Name not found\n");
    }
    destroy_database(&db);
    return 0;
}
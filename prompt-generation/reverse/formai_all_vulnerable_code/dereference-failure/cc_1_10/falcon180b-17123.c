//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} KeyValuePair;

typedef struct {
    KeyValuePair *keys;
    int numKeys;
} Database;

Database *createDatabase() {
    Database *db = malloc(sizeof(Database));
    db->keys = NULL;
    db->numKeys = 0;
    return db;
}

void addKeyValuePair(Database *db, char *key, char *value) {
    KeyValuePair *pair = malloc(sizeof(KeyValuePair));
    strcpy(pair->key, key);
    strcpy(pair->value, value);
    db->keys = realloc(db->keys, sizeof(KeyValuePair) * (db->numKeys + 1));
    db->keys[db->numKeys] = *pair;
    db->numKeys++;
}

void printDatabase(Database *db) {
    for (int i = 0; i < db->numKeys; i++) {
        printf("%s: %s\n", db->keys[i].key, db->keys[i].value);
    }
}

void destroyDatabase(Database *db) {
    free(db->keys);
    free(db);
}

int main() {
    Database *db = createDatabase();

    addKeyValuePair(db, "name", "John");
    addKeyValuePair(db, "age", "30");
    addKeyValuePair(db, "city", "New York");

    printDatabase(db);

    destroyDatabase(db);

    return 0;
}
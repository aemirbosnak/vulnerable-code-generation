//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValue;

typedef struct {
    KeyValue *keys;
    int numKeys;
} Database;

void initDatabase(Database *db) {
    db->keys = NULL;
    db->numKeys = 0;
}

int addKey(Database *db, char *key, char *value) {
    KeyValue *newKeyValue = malloc(sizeof(KeyValue));
    strncpy(newKeyValue->key, key, MAX_KEY_LENGTH);
    strncpy(newKeyValue->value, value, MAX_VALUE_LENGTH);
    db->keys = realloc(db->keys, sizeof(KeyValue) * (db->numKeys + 1));
    db->keys[db->numKeys] = *newKeyValue;
    db->numKeys++;
    return 0;
}

char *getValue(Database *db, char *key) {
    int i;
    for (i = 0; i < db->numKeys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            return db->keys[i].value;
        }
    }
    return NULL;
}

int main() {
    Database db;
    initDatabase(&db);
    addKey(&db, "name", "John Doe");
    addKey(&db, "age", "30");
    addKey(&db, "city", "New York");
    printf("Name: %s\n", getValue(&db, "name"));
    printf("Age: %s\n", getValue(&db, "age"));
    printf("City: %s\n", getValue(&db, "city"));
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValuePair;

typedef struct {
    KeyValuePair *keys;
    int numKeys;
} Database;

void initDatabase(Database *db) {
    db->keys = NULL;
    db->numKeys = 0;
}

void addKeyValuePair(Database *db, char *key, char *value) {
    KeyValuePair *newPair = malloc(sizeof(KeyValuePair));
    strcpy(newPair->key, key);
    strcpy(newPair->value, value);
    db->keys = realloc(db->keys, sizeof(KeyValuePair) * (db->numKeys + 1));
    db->keys[db->numKeys] = *newPair;
    db->numKeys++;
}

int searchDatabase(Database *db, char *key) {
    for (int i = 0; i < db->numKeys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Database db;
    initDatabase(&db);

    addKeyValuePair(&db, "name", "John");
    addKeyValuePair(&db, "age", "25");
    addKeyValuePair(&db, "address", "123 Main St");

    int index = searchDatabase(&db, "name");
    if (index!= -1) {
        printf("Value for key 'name': %s\n", db.keys[index].value);
    } else {
        printf("Key 'name' not found in database.\n");
    }

    return 0;
}
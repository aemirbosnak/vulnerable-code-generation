//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 1000
#define MAX_NUM_VALUES 10000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

typedef struct {
    KeyValuePair *keys;
    KeyValuePair *values;
    int numKeys;
    int numValues;
} Database;

Database *createDatabase() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->keys = (KeyValuePair *)malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    db->values = (KeyValuePair *)malloc(MAX_NUM_VALUES * sizeof(KeyValuePair));
    db->numKeys = 0;
    db->numValues = 0;
    return db;
}

void destroyDatabase(Database *db) {
    free(db->keys);
    free(db->values);
    free(db);
}

int addKeyValuePair(Database *db, char *key, char *value) {
    if (db->numKeys >= MAX_NUM_KEYS || db->numValues >= MAX_NUM_VALUES) {
        return -1;
    }

    KeyValuePair *kv = &db->keys[db->numKeys];
    strcpy(kv->key, key);
    strcpy(kv->value, value);

    KeyValuePair *v = &db->values[db->numValues];
    strcpy(v->key, key);
    strcpy(v->value, value);

    db->numKeys++;
    db->numValues++;

    return 0;
}

int searchKey(Database *db, char *key) {
    for (int i = 0; i < db->numKeys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            return i;
        }
    }

    return -1;
}

int searchValue(Database *db, char *value) {
    for (int i = 0; i < db->numValues; i++) {
        if (strcmp(db->values[i].value, value) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    Database *db = createDatabase();

    addKeyValuePair(db, "name", "John");
    addKeyValuePair(db, "age", "30");

    int keyIndex = searchKey(db, "name");
    int valueIndex = searchValue(db, "30");

    printf("Key index: %d\n", keyIndex);
    printf("Value index: %d\n", valueIndex);

    destroyDatabase(db);

    return 0;
}
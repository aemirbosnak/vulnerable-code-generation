//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValue;

typedef struct {
    KeyValue *keys;
    KeyValue *values;
    int numKeys;
    int numValues;
} Database;

void initDatabase(Database *db) {
    db->keys = (KeyValue *)malloc(MAX_NUM_KEYS * sizeof(KeyValue));
    db->values = (KeyValue *)malloc(MAX_NUM_VALUES * sizeof(KeyValue));
    db->numKeys = 0;
    db->numValues = 0;
}

void addKey(Database *db, char *key) {
    KeyValue *kv = &db->keys[db->numKeys];
    strcpy(kv->key, key);
    db->numKeys++;
}

void addValue(Database *db, char *value) {
    KeyValue *kv = &db->values[db->numValues];
    strcpy(kv->value, value);
    db->numValues++;
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

void printKeyValues(Database *db) {
    for (int i = 0; i < db->numKeys; i++) {
        int valueIndex = searchValue(db, db->keys[i].value);
        printf("%s -> %s\n", db->keys[i].key, db->values[valueIndex].value);
    }
}

int main() {
    Database db;
    initDatabase(&db);

    addKey(&db, "apple");
    addKey(&db, "banana");
    addKey(&db, "cherry");

    addValue(&db, "red");
    addValue(&db, "yellow");
    addValue(&db, "green");

    printKeyValues(&db);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 1000
#define MAX_NUM_VALUES 10000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValuePair;

typedef struct {
    int numKeys;
    int numValues;
    KeyValuePair *keys;
    KeyValuePair *values;
} Database;

void initializeDatabase(Database *db) {
    db->numKeys = 0;
    db->numValues = 0;
    db->keys = (KeyValuePair *) malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    db->values = (KeyValuePair *) malloc(MAX_NUM_VALUES * sizeof(KeyValuePair));
}

void addKeyValuePair(Database *db, char *key, char *value) {
    if (db->numKeys >= MAX_NUM_KEYS || db->numValues >= MAX_NUM_VALUES) {
        printf("Error: database is full.\n");
        return;
    }
    strcpy(db->keys[db->numKeys].key, key);
    strcpy(db->values[db->numValues].value, value);
    db->numKeys++;
    db->numValues++;
}

void searchKey(Database *db, char *key) {
    int i;
    for (i = 0; i < db->numKeys; i++) {
        if (strcmp(db->keys[i].key, key) == 0) {
            printf("Value: %s\n", db->values[i].value);
            return;
        }
    }
    printf("Error: key not found.\n");
}

int main() {
    Database db;
    initializeDatabase(&db);
    addKeyValuePair(&db, "apple", "red");
    addKeyValuePair(&db, "banana", "yellow");
    addKeyValuePair(&db, "cherry", "red");
    searchKey(&db, "apple");
    searchKey(&db, "grape");
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

typedef struct {
    KeyValuePair *pairs;
    int numPairs;
} Database;

Database *createDatabase() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->pairs = (KeyValuePair *)malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    db->numPairs = 0;
    return db;
}

void destroyDatabase(Database *db) {
    free(db->pairs);
    free(db);
}

int addKeyValuePair(Database *db, char *key, char *value) {
    if (db->numPairs >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of key-value pairs reached.\n");
        return -1;
    }

    strncpy(db->pairs[db->numPairs].key, key, MAX_KEY_LENGTH);
    strncpy(db->pairs[db->numPairs].value, value, MAX_VALUE_LENGTH);
    db->numPairs++;

    return 0;
}

int searchKeyValuePair(Database *db, char *key) {
    for (int i = 0; i < db->numPairs; i++) {
        if (strcmp(db->pairs[i].key, key) == 0) {
            printf("Key: %s\nValue: %s\n", db->pairs[i].key, db->pairs[i].value);
            return 0;
        }
    }

    printf("Key not found.\n");
    return -1;
}

int main() {
    Database *db = createDatabase();

    addKeyValuePair(db, "name", "John");
    addKeyValuePair(db, "age", "30");
    addKeyValuePair(db, "city", "New York");

    searchKeyValuePair(db, "name");
    searchKeyValuePair(db, "age");
    searchKeyValuePair(db, "city");

    destroyDatabase(db);

    return 0;
}
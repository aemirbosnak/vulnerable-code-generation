//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: accurate
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
    KeyValuePair *data;
    int num_keys;
    int num_values;
} Database;

void createDatabase(Database *db) {
    db->data = (KeyValuePair *) malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    db->num_keys = 0;
    db->num_values = 0;
}

void destroyDatabase(Database *db) {
    free(db->data);
}

int addKeyValuePair(Database *db, const char *key, const char *value) {
    if (db->num_keys >= MAX_NUM_KEYS || db->num_values >= MAX_NUM_VALUES) {
        return -1;
    }

    KeyValuePair *pair = &db->data[db->num_keys];
    strcpy(pair->key, key);
    strcpy(pair->value, value);

    db->num_keys++;
    db->num_values++;

    return 0;
}

int searchByKey(Database *db, const char *key, char *value) {
    for (int i = 0; i < db->num_keys; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            strcpy(value, db->data[i].value);
            return 0;
        }
    }

    return -1;
}

int main() {
    Database db;
    createDatabase(&db);

    addKeyValuePair(&db, "name", "John");
    addKeyValuePair(&db, "age", "30");

    char value[MAX_VALUE_LENGTH];
    searchByKey(&db, "name", value);
    printf("Name: %s\n", value);

    searchByKey(&db, "address", value);
    printf("Address: %s\n", value);

    destroyDatabase(&db);

    return 0;
}
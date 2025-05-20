//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
//Romeo and Juliet style C Database Indexing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_VALUE_SIZE 1024
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValuePair;

typedef struct {
    KeyValuePair *data;
    int numKeys;
    int maxKeys;
} Database;

void initDatabase(Database *db) {
    db->data = (KeyValuePair *) malloc(MAX_NUM_KEYS * sizeof(KeyValuePair));
    db->numKeys = 0;
    db->maxKeys = MAX_NUM_KEYS;
}

void destroyDatabase(Database *db) {
    free(db->data);
    db->numKeys = 0;
    db->maxKeys = MAX_NUM_KEYS;
}

int addKeyValuePair(Database *db, char *key, char *value) {
    if (db->numKeys >= db->maxKeys) {
        printf("Error: database is full.\n");
        return 0;
    }

    KeyValuePair *pair = &db->data[db->numKeys];
    strncpy(pair->key, key, MAX_KEY_SIZE);
    strncpy(pair->value, value, MAX_VALUE_SIZE);
    db->numKeys++;

    return 1;
}

int searchKey(Database *db, char *key) {
    int i;
    for (i = 0; i < db->numKeys; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            printf("%s\n", db->data[i].value);
            return 1;
        }
    }

    printf("Key not found.\n");
    return 0;
}

int main() {
    Database db;
    initDatabase(&db);

    addKeyValuePair(&db, "Romeo", "He is the son of Montague and falls in love with Juliet.");
    addKeyValuePair(&db, "Juliet", "She is the daughter of Capulet and falls in love with Romeo.");
    addKeyValuePair(&db, "Montague", "He is the father of Romeo and the head of the Montague family.");
    addKeyValuePair(&db, "Capulet", "He is the father of Juliet and the head of the Capulet family.");

    searchKey(&db, "Romeo");
    searchKey(&db, "Juliet");
    searchKey(&db, "Montague");
    searchKey(&db, "Capulet");

    destroyDatabase(&db);

    return 0;
}
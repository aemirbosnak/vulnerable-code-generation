//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record *data;
    int size;
    int capacity;
} Database;

Database *createDatabase() {
    Database *db = malloc(sizeof(Database));
    db->data = NULL;
    db->size = 0;
    db->capacity = 10;
    return db;
}

void destroyDatabase(Database *db) {
    for (int i = 0; i < db->size; i++) {
        free(db->data[i].key);
        free(db->data[i].value);
    }
    free(db->data);
    free(db);
}

void addRecord(Database *db, char *key, char *value) {
    if (db->size >= db->capacity) {
        db->capacity *= 2;
        db->data = realloc(db->data, db->capacity * sizeof(Record));
    }
    Record *record = &db->data[db->size];
    strncpy(record->key, key, MAX_KEY_LENGTH);
    strncpy(record->value, value, MAX_VALUE_LENGTH);
    db->size++;
}

void removeRecord(Database *db, char *key) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            free(db->data[i].key);
            free(db->data[i].value);
            for (int j = i; j < db->size - 1; j++) {
                Record *record = &db->data[j];
                strcpy(record->key, db->data[j+1].key);
                strcpy(record->value, db->data[j+1].value);
            }
            db->size--;
            return;
        }
    }
}

char *getValue(Database *db, char *key) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            return db->data[i].value;
        }
    }
    return NULL;
}

void printDatabase(Database *db) {
    for (int i = 0; i < db->size; i++) {
        printf("%s -> %s\n", db->data[i].key, db->data[i].value);
    }
}

int main() {
    Database *db = createDatabase();
    addRecord(db, "name", "John");
    addRecord(db, "age", "30");
    addRecord(db, "city", "New York");
    printDatabase(db);
    char *value = getValue(db, "age");
    printf("Age: %s\n", value);
    removeRecord(db, "age");
    printDatabase(db);
    destroyDatabase(db);
    return 0;
}
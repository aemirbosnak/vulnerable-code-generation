//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    int value;
} Record;

typedef struct {
    Record *records;
    int count;
} Database;

void createDatabase(Database *db) {
    db->records = NULL;
    db->count = 0;
}

void addRecord(Database *db, char *key, int value) {
    Record *record = malloc(sizeof(Record));
    strcpy(record->key, key);
    record->value = value;
    db->records = realloc(db->records, sizeof(Record) * ++db->count);
    db->records[db->count - 1] = *record;
    free(record);
}

int searchRecord(Database *db, char *key) {
    int i;
    for (i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            return db->records[i].value;
        }
    }
    return -1;
}

void deleteRecord(Database *db, char *key) {
    int i;
    for (i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            db->count--;
            db->records = realloc(db->records, sizeof(Record) * db->count);
        }
    }
}

void printDatabase(Database *db) {
    int i;
    for (i = 0; i < db->count; i++) {
        printf("%s %d\n", db->records[i].key, db->records[i].value);
    }
}

int main() {
    Database db;
    createDatabase(&db);

    addRecord(&db, "John", 20);
    addRecord(&db, "Jane", 25);
    addRecord(&db, "Mike", 30);

    printDatabase(&db);

    int age = searchRecord(&db, "John");
    printf("John's age is %d\n", age);

    deleteRecord(&db, "John");

    printDatabase(&db);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
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
    Record *records;
    int capacity;
    int size;
} Database;

void init_database(Database *db, int capacity) {
    db->records = (Record *)malloc(capacity * sizeof(Record));
    db->capacity = capacity;
    db->size = 0;
}

void destroy_database(Database *db) {
    free(db->records);
}

int hash_key(char *key) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31) ^ (*key++);
    }
    return hash % MAX_KEY_LENGTH;
}

void insert_record(Database *db, char *key, char *value) {
    int index = hash_key(key);
    while (db->records[index].key[0]!= '\0' && strcmp(db->records[index].key, key)!= 0) {
        index = (index + 1) % MAX_KEY_LENGTH;
    }
    strcpy(db->records[index].key, key);
    strcpy(db->records[index].value, value);
    db->size++;
}

char *search_record(Database *db, char *key) {
    int index = hash_key(key);
    while (db->records[index].key[0]!= '\0' && strcmp(db->records[index].key, key)!= 0) {
        index = (index + 1) % MAX_KEY_LENGTH;
    }
    if (db->records[index].key[0] == '\0') {
        return NULL;
    } else {
        return db->records[index].value;
    }
}

int main() {
    Database db;
    init_database(&db, 1000);

    insert_record(&db, "apple", "red");
    insert_record(&db, "banana", "yellow");
    insert_record(&db, "cherry", "red");

    char *value1 = search_record(&db, "apple");
    char *value2 = search_record(&db, "banana");
    char *value3 = search_record(&db, "cherry");

    printf("Value for apple: %s\n", value1);
    printf("Value for banana: %s\n", value2);
    printf("Value for cherry: %s\n", value3);

    destroy_database(&db);

    return 0;
}
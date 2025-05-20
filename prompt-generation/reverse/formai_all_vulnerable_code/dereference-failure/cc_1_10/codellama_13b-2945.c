//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_VAL_LEN 256

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
} record_t;

typedef struct {
    record_t *records;
    int capacity;
    int size;
} database_t;

void init_database(database_t *db, int capacity) {
    db->records = (record_t*)malloc(sizeof(record_t) * capacity);
    db->capacity = capacity;
    db->size = 0;
}

int insert_record(database_t *db, char *key, char *value) {
    if (db->size == db->capacity) {
        return -1;
    }
    strcpy(db->records[db->size].key, key);
    strcpy(db->records[db->size].value, value);
    db->size++;
    return 0;
}

record_t *find_record(database_t *db, char *key) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

int update_record(database_t *db, char *key, char *value) {
    record_t *record = find_record(db, key);
    if (record == NULL) {
        return -1;
    }
    strcpy(record->value, value);
    return 0;
}

int delete_record(database_t *db, char *key) {
    record_t *record = find_record(db, key);
    if (record == NULL) {
        return -1;
    }
    strcpy(record->key, "");
    strcpy(record->value, "");
    return 0;
}

int main() {
    database_t db;
    init_database(&db, 100);
    insert_record(&db, "key1", "value1");
    insert_record(&db, "key2", "value2");
    insert_record(&db, "key3", "value3");
    printf("key1: %s\n", find_record(&db, "key1")->value);
    printf("key2: %s\n", find_record(&db, "key2")->value);
    printf("key3: %s\n", find_record(&db, "key3")->value);
    update_record(&db, "key1", "new_value1");
    printf("key1: %s\n", find_record(&db, "key1")->value);
    delete_record(&db, "key2");
    printf("key2: %s\n", find_record(&db, "key2")->value);
    return 0;
}
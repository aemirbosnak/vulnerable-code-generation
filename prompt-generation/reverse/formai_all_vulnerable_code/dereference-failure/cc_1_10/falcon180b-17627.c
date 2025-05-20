//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Database;

void init_database(Database *db, int max_records) {
    db->records = malloc(max_records * sizeof(Record));
    db->num_records = 0;
    db->max_records = max_records;
}

void destroy_database(Database *db) {
    free(db->records);
}

int add_record(Database *db, char *key, char *value) {
    if (db->num_records >= db->max_records) {
        return -1;
    }

    Record *rec = &db->records[db->num_records];
    strncpy(rec->key, key, MAX_KEY_LEN);
    strncpy(rec->value, value, MAX_VALUE_LEN);

    db->num_records++;
    return 0;
}

int search_record(Database *db, char *key) {
    for (int i = 0; i < db->num_records; i++) {
        Record *rec = &db->records[i];
        if (strcmp(rec->key, key) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    Database db;
    init_database(&db, 10);

    char *key = "John";
    char *value = "Smith";
    int index = add_record(&db, key, value);
    printf("Added record with key '%s' and value '%s' at index %d\n", key, value, index);

    char *search_key = "John";
    int search_index = search_record(&db, search_key);
    if (search_index!= -1) {
        printf("Found record with key '%s' at index %d\n", search_key, search_index);
    } else {
        printf("Record not found\n");
    }

    destroy_database(&db);
    return 0;
}
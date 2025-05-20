//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_DATA_SIZE 1000
#define MAX_KEY_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    char data[MAX_DATA_SIZE];
} Record;

typedef struct {
    int size;
    Record *records;
} Database;

void init_database(Database *db) {
    db->size = 0;
    db->records = NULL;
}

int add_record(Database *db, char *key, char *data) {
    Record *record = malloc(sizeof(Record));
    strcpy(record->key, key);
    strcpy(record->data, data);
    db->records = realloc(db->records, sizeof(Record) * ++db->size);
    db->records[db->size - 1] = *record;
    return db->size;
}

int search_record(Database *db, char *key) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

int delete_record(Database *db, char *key) {
    int index = search_record(db, key);
    if (index == -1) {
        return -1;
    }
    db->size--;
    db->records = realloc(db->records, sizeof(Record) * db->size);
    return 0;
}

int update_record(Database *db, char *key, char *data) {
    int index = search_record(db, key);
    if (index == -1) {
        return -1;
    }
    strcpy(db->records[index].data, data);
    return 0;
}

void print_database(Database *db) {
    int i;
    for (i = 0; i < db->size; i++) {
        printf("%s -> %s\n", db->records[i].key, db->records[i].data);
    }
}

int main() {
    Database db;
    init_database(&db);
    add_record(&db, "Name", "John");
    add_record(&db, "Age", "25");
    add_record(&db, "City", "New York");
    print_database(&db);
    update_record(&db, "Age", "26");
    print_database(&db);
    delete_record(&db, "City");
    print_database(&db);
    return 0;
}
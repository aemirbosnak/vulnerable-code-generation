//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int capacity;
} Database;

void init_database(Database *db, int capacity) {
    db->records = malloc(capacity * sizeof(Record));
    db->num_records = 0;
    db->capacity = capacity;
}

void destroy_database(Database *db) {
    free(db->records);
}

int add_record(Database *db, char *name, char *value) {
    if (db->num_records >= db->capacity) {
        return -1;
    }

    Record *record = db->records + db->num_records;
    strcpy(record->name, name);
    strcpy(record->value, value);

    db->num_records++;
    return 0;
}

int search_record(Database *db, char *name, char *value) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = db->records + i;

        if (strcmp(record->name, name) == 0) {
            strcpy(value, record->value);
            return 0;
        }
    }

    return -1;
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "John", "Doe");
    add_record(&db, "Jane", "Doe");
    add_record(&db, "Bob", "Smith");

    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];

    printf("Searching for John Doe...\n");
    search_record(&db, "John", value);
    printf("Value: %s\n", value);

    printf("Searching for Jane Smith...\n");
    search_record(&db, "Jane", value);
    printf("Value: %s\n", value);

    destroy_database(&db);

    return 0;
}
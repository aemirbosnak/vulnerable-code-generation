//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void create_database(Database *db) {
    db->records = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->records[i].num_fields; j++) {
            free(db->records[i].fields[j]);
        }
        free(db->records[i].fields);
    }
    free(db->records);
}

void add_field(Record *record, char *value) {
    if (record->num_fields >= MAX_FIELD_SIZE) {
        fprintf(stderr, "Error: Record has too many fields.\n");
        exit(1);
    }
    record->fields[record->num_fields++] = strdup(value);
}

void print_record(Record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
    }
    printf("\n");
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        print_record(&db->records[i]);
    }
}

int main() {
    Database db;
    create_database(&db);

    char *fields[MAX_FIELD_SIZE];
    int num_fields = 0;

    while (1) {
        printf("Enter a record (enter 'done' when finished):\n");
        char *input = fgets(fields[num_fields], MAX_FIELD_SIZE, stdin);
        if (strcmp(input, "done") == 0) {
            break;
        }
        add_field(&db.records[db.num_records++], input);
        num_fields = 0;
    }

    printf("Database:\n");
    print_database(&db);

    destroy_database(&db);

    return 0;
}
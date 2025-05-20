//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 10
#define MAX_FIELD_SIZE 50

struct record {
    int id;
    char *fields[MAX_FIELDS];
    int num_fields;
};

struct table {
    struct record *records;
    int num_records;
};

void init_table(struct table *table) {
    table->records = NULL;
    table->num_records = 0;
}

void add_record(struct table *table, int id, char *fields[], int num_fields) {
    struct record *record = (struct record *)malloc(sizeof(struct record));
    record->id = id;
    record->num_fields = num_fields;
    for (int i = 0; i < num_fields; i++) {
        record->fields[i] = strdup(fields[i]);
    }
    table->records = realloc(table->records, sizeof(struct record) * (table->num_records + 1));
    table->records[table->num_records] = *record;
    table->num_records++;
}

void print_record(struct record *record) {
    printf("ID: %d\n", record->id);
    for (int i = 0; i < record->num_fields; i++) {
        printf("Field %d: %s\n", i+1, record->fields[i]);
    }
}

void print_table(struct table *table) {
    for (int i = 0; i < table->num_records; i++) {
        print_record(table->records + i);
    }
}

void free_table(struct table *table) {
    for (int i = 0; i < table->num_records; i++) {
        for (int j = 0; j < table->records[i].num_fields; j++) {
            free(table->records[i].fields[j]);
        }
        free(table->records[i].fields);
    }
    free(table->records);
}

int main() {
    struct table table;
    init_table(&table);

    add_record(&table, 1, (char *[]){"John", "Doe", "25"}, 3);
    add_record(&table, 2, (char *[]){"Jane", "Doe", "30"}, 3);

    print_table(&table);

    free_table(&table);

    return 0;
}
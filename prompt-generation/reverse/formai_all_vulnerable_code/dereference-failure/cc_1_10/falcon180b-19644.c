//Falcon-180B DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char *field_name;
    char *data;
} Record;

typedef struct {
    char *name;
    int num_records;
    Record *records;
} Table;

void create_table(Table *table, char *name) {
    table->name = name;
    table->num_records = 0;
    table->records = NULL;
}

void add_record(Table *table, Record *record) {
    table->records = realloc(table->records, sizeof(Record) * (table->num_records + 1));
    table->records[table->num_records] = *record;
    table->num_records++;
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    printf("---------------------------------\n");
    for (int i = 0; i < table->num_records; i++) {
        printf("%s: %s\n", table->records[i].field_name, table->records[i].data);
    }
}

void delete_table(Table *table) {
    free(table->records);
    free(table->name);
    free(table);
}

void create_record(Record *record, char *field_name, char *data) {
    record->field_name = field_name;
    record->data = data;
}

int main() {
    Table table;
    create_table(&table, "Employees");

    Record record1;
    create_record(&record1, "Name", "John Doe");
    create_record(&record1, "Age", "30");
    create_record(&record1, "Position", "Manager");
    add_record(&table, &record1);

    Record record2;
    create_record(&record2, "Name", "Jane Doe");
    create_record(&record2, "Age", "25");
    create_record(&record2, "Position", "Assistant");
    add_record(&table, &record2);

    print_table(&table);

    delete_table(&table);

    return 0;
}
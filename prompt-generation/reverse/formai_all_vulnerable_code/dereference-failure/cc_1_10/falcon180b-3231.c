//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD 10
#define MAX_RECORD 100

typedef struct {
    char *field;
    int length;
    int offset;
} field_t;

typedef struct {
    field_t field[MAX_FIELD];
    int num_field;
    char record[MAX_RECORD];
} record_t;

typedef struct {
    record_t record;
    int num_record;
    int num_field;
} table_t;

void init_table(table_t *table)
{
    table->num_record = 0;
    table->num_field = 0;
}

void add_field(table_t *table, char *name, int length, int offset)
{
    if (table->num_field >= MAX_FIELD) {
        printf("Error: Maximum number of fields reached.\n");
        return;
    }

    field_t *field = &table->record.field[table->num_field];
    field->field = strdup(name);
    field->length = length;
    field->offset = offset;

    table->num_field++;
}

void add_record(table_t *table, char *record)
{
    if (table->num_record >= MAX_RECORD) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    strcpy(table->record.record, record);
    table->num_record++;
}

int main()
{
    table_t table;
    init_table(&table);

    add_field(&table, "name", 20, 0);
    add_field(&table, "age", 3, 20);
    add_field(&table, "gender", 6, 23);

    add_record(&table, "John Smith 25 M");
    add_record(&table, "Jane Doe 30 F");

    return 0;
}
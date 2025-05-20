//Falcon-180B DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100

typedef struct {
    char name[MAX_COLUMNS];
    int id;
} Record;

typedef struct {
    Record *data;
    int num_rows;
    int num_columns;
} Table;

void create_table(Table *table, int num_rows, int num_columns) {
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = (Record *) malloc(num_rows * sizeof(Record));
}

void add_record(Table *table, int row, char *name, int id) {
    Record *record = &table->data[row];
    strcpy(record->name, name);
    record->id = id;
}

int search_record(Table *table, int row, char *name) {
    Record *record = &table->data[row];
    if (strcmp(record->name, name) == 0) {
        return record->id;
    } else {
        return -1;
    }
}

int main() {
    Table table;
    create_table(&table, 5, 2);

    add_record(&table, 0, "John", 1);
    add_record(&table, 1, "Jane", 2);
    add_record(&table, 2, "Bob", 3);
    add_record(&table, 3, "Alice", 4);
    add_record(&table, 4, "Charlie", 5);

    int id = search_record(&table, 2, "Bob");
    printf("ID for Bob: %d\n", id);

    return 0;
}
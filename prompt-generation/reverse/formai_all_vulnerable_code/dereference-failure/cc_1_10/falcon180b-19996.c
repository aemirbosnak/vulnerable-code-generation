//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

typedef struct {
    Record* records;
    int num_records;
    int capacity;
} Table;

void init_table(Table* table, int capacity) {
    table->records = malloc(capacity * sizeof(Record));
    table->num_records = 0;
    table->capacity = capacity;
}

void add_record(Table* table, char* key, char* value) {
    if (table->num_records >= table->capacity) {
        printf("Table is full\n");
        return;
    }

    strcpy(table->records[table->num_records].key, key);
    strcpy(table->records[table->num_records].value, value);
    table->num_records++;
}

void print_records(Table* table) {
    for (int i = 0; i < table->num_records; i++) {
        printf("%s -> %s\n", table->records[i].key, table->records[i].value);
    }
}

int main() {
    Table table;
    init_table(&table, 10);

    add_record(&table, "John", "25");
    add_record(&table, "Jane", "30");
    add_record(&table, "Bob", "40");

    print_records(&table);

    return 0;
}
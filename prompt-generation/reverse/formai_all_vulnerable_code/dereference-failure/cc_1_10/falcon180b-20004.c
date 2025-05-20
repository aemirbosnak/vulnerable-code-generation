//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
} Table;

Table *create_table() {
    Table *table = malloc(sizeof(Table));
    table->records = malloc(10 * sizeof(Record));
    table->num_records = 0;
    return table;
}

void add_record(Table *table, char *key, char *value) {
    Record *record = malloc(sizeof(Record));
    strcpy(record->key, key);
    strcpy(record->value, value);
    table->records[table->num_records++] = *record;
}

int search_record(Table *table, char *key) {
    for (int i = 0; i < table->num_records; i++) {
        if (strcmp(table->records[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

void print_record(Record *record) {
    printf("Key: %s\nValue: %s\n", record->key, record->value);
}

int main() {
    Table *table = create_table();
    add_record(table, "John", "Doe");
    add_record(table, "Jane", "Doe");
    add_record(table, "Bob", "Smith");
    int index = search_record(table, "John");
    if (index!= -1) {
        print_record(&table->records[index]);
    }
    return 0;
}
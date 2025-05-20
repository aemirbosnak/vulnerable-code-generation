//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 200
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} record_t;

typedef struct {
    record_t *records;
    int num_records;
} table_t;

void table_init(table_t *table) {
    table->records = (record_t *) malloc(MAX_NUM_KEYS * sizeof(record_t));
    table->num_records = 0;
}

void table_insert(table_t *table, char *key, char *value) {
    if (table->num_records >= MAX_NUM_KEYS) {
        printf("Table is full\n");
        return;
    }

    strcpy(table->records[table->num_records].key, key);
    strcpy(table->records[table->num_records].value, value);
    table->num_records++;
}

int table_search(table_t *table, char *key) {
    int i;
    for (i = 0; i < table->num_records; i++) {
        if (strcmp(table->records[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

void table_delete(table_t *table, char *key) {
    int index = table_search(table, key);
    if (index == -1) {
        printf("Key not found\n");
        return;
    }

    table->num_records--;
    memmove(&table->records[index], &table->records[index + 1],
            (table->num_records - index) * sizeof(record_t));
}

void table_print(table_t *table) {
    int i;
    for (i = 0; i < table->num_records; i++) {
        printf("%s -> %s\n", table->records[i].key, table->records[i].value);
    }
}

int main() {
    table_t table;
    table_init(&table);

    table_insert(&table, "apple", "red");
    table_insert(&table, "banana", "yellow");
    table_insert(&table, "cherry", "red");

    table_print(&table);

    table_delete(&table, "apple");

    table_print(&table);

    return 0;
}
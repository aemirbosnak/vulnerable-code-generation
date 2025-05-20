//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 1024
#define MAX_INDEX_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

typedef struct {
    int num_records;
    Record *records;
} Index;

void create_index(Index *index) {
    index->num_records = 0;
    index->records = NULL;
}

void add_record(Index *index, char *key, char *value) {
    Record *record = malloc(sizeof(Record));
    strncpy(record->key, key, MAX_KEY_SIZE);
    strncpy(record->value, value, MAX_VALUE_SIZE);
    index->records = realloc(index->records, sizeof(Record) * (index->num_records + 1));
    index->records[index->num_records] = *record;
    index->num_records++;
}

void search_index(Index *index, char *key) {
    for (int i = 0; i < index->num_records; i++) {
        if (strcmp(index->records[i].key, key) == 0) {
            printf("Value: %s\n", index->records[i].value);
            return;
        }
    }
    printf("No record found.\n");
}

int main() {
    Index index;
    create_index(&index);

    add_record(&index, "John", "Doe");
    add_record(&index, "Jane", "Doe");
    add_record(&index, "Bob", "Smith");

    search_index(&index, "John");
    search_index(&index, "Jane");
    search_index(&index, "Bob");
    search_index(&index, "Alice");

    return 0;
}
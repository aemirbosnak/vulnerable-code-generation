//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
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
    int max_records;
} Index;

Index *create_index(int max_records) {
    Index *index = malloc(sizeof(Index));
    index->records = malloc(max_records * sizeof(Record));
    index->num_records = 0;
    index->max_records = max_records;
    return index;
}

void destroy_index(Index *index) {
    free(index->records);
    free(index);
}

int add_record(Index *index, char *key, char *value) {
    if (index->num_records == index->max_records) {
        return -1;
    }

    Record *record = &index->records[index->num_records];
    strcpy(record->key, key);
    strcpy(record->value, value);
    index->num_records++;

    return 0;
}

int search_record(Index *index, char *key, char *value) {
    for (int i = 0; i < index->num_records; i++) {
        Record *record = &index->records[i];
        if (strcmp(record->key, key) == 0) {
            strcpy(value, record->value);
            return 0;
        }
    }

    return -1;
}

int main() {
    Index *index = create_index(10);

    add_record(index, "John", "Doe");
    add_record(index, "Jane", "Doe");
    add_record(index, "Bob", "Smith");

    char value[MAX_VALUE_LEN];
    search_record(index, "John", value);
    printf("John: %s\n", value);

    search_record(index, "Alice", value);
    printf("Alice: %s\n", value);

    destroy_index(index);

    return 0;
}
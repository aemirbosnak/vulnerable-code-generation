//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_KEY_LEN 255
#define MAX_VALUE_LEN 1024
#define MAX_INDEX_SIZE 1000000

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Index;

void init_index(Index *index) {
    index->records = malloc(MAX_INDEX_SIZE * sizeof(Record));
    index->num_records = 0;
    index->max_records = MAX_INDEX_SIZE;
}

void add_record(Index *index, const char *key, const char *value) {
    if (index->num_records >= index->max_records) {
        printf("Index is full\n");
        return;
    }

    Record *record = &index->records[index->num_records];
    strncpy(record->key, key, MAX_KEY_LEN);
    strncpy(record->value, value, MAX_VALUE_LEN);
    index->num_records++;
}

bool search_index(Index *index, const char *key, char *value, int value_len) {
    int i;
    for (i = 0; i < index->num_records; i++) {
        Record *record = &index->records[i];
        if (strcmp(record->key, key) == 0) {
            strncpy(value, record->value, value_len);
            return true;
        }
    }
    return false;
}

int main() {
    Index index;
    init_index(&index);

    add_record(&index, "apple", "red");
    add_record(&index, "banana", "yellow");
    add_record(&index, "cherry", "red");

    char value[MAX_VALUE_LEN];
    if (search_index(&index, "banana", value, sizeof(value))) {
        printf("Banana is %s\n", value);
    } else {
        printf("Banana not found\n");
    }

    return 0;
}
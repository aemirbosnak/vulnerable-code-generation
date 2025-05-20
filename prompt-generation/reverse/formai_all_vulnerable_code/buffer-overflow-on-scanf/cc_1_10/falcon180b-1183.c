//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_DATA_LEN 1000
#define MAX_INDEX_LEN 1000
#define MAX_NUM_RECORDS 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];
} Record;

typedef struct {
    char index[MAX_INDEX_LEN];
    int num_records;
    Record *records;
} Index;

void init_index(Index *index) {
    index->num_records = 0;
    index->records = NULL;
}

int compare_keys(const void *key1, const void *key2) {
    return strcmp(*(char **)key1, *(char **)key2);
}

int compare_index(const void *index1, const void *index2) {
    return strcmp(*(char **)index1, *(char **)index2);
}

void add_record(Index *index, Record *record) {
    index->records = realloc(index->records, sizeof(Record) * (index->num_records + 1));
    index->records[index->num_records] = *record;
    index->num_records++;
}

void print_index(Index *index) {
    printf("Index:\n");
    for (int i = 0; i < index->num_records; i++) {
        printf("%s\n", index->records[i].key);
    }
}

void print_record(Record *record) {
    printf("Key: %s\nData: %s\n", record->key, record->data);
}

int main() {
    Index index;
    init_index(&index);

    Record record;
    while (1) {
        printf("Enter key (or 'quit' to exit): ");
        scanf("%s", record.key);
        if (strcmp(record.key, "quit") == 0) {
            break;
        }

        printf("Enter data: ");
        scanf("%s", record.data);
        add_record(&index, &record);
    }

    printf("Index:\n");
    print_index(&index);

    return 0;
}
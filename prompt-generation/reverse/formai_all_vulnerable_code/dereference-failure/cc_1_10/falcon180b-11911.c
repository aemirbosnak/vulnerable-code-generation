//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    int size;
    int capacity;
    Record *records;
} Index;

void init_index(Index *index) {
    index->size = 0;
    index->capacity = 10;
    index->records = malloc(index->capacity * sizeof(Record));
}

void destroy_index(Index *index) {
    free(index->records);
}

int index_add_record(Index *index, const char *name, const char *value) {
    if (index->size == index->capacity) {
        index->capacity *= 2;
        index->records = realloc(index->records, index->capacity * sizeof(Record));
    }

    strcpy(index->records[index->size].name, name);
    strcpy(index->records[index->size].value, value);
    index->size++;

    return 0;
}

int index_get_record(Index *index, const char *name, char *value, int value_length) {
    int i;
    for (i = 0; i < index->size; i++) {
        if (strcmp(index->records[i].name, name) == 0) {
            strncpy(value, index->records[i].value, value_length);
            return 0;
        }
    }

    return -1;
}

int main() {
    Index index;
    init_index(&index);

    index_add_record(&index, "John", "Doe");
    index_add_record(&index, "Jane", "Doe");
    index_add_record(&index, "Bob", "Smith");

    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];

    while (1) {
        printf("Enter name to search: ");
        scanf("%s", name);

        int result = index_get_record(&index, name, value, MAX_VALUE_LENGTH);
        if (result == 0) {
            printf("Value: %s\n", value);
        } else {
            printf("Not found\n");
        }
    }

    destroy_index(&index);

    return 0;
}
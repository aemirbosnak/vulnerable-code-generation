//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *key;
    char *value;
} record_t;

record_t database[MAX_RECORDS];
int num_records = 0;

void add_record(char *key, char *value) {
    if (num_records >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    record_t new_record;
    strcpy(new_record.key, key);
    strcpy(new_record.value, value);

    database[num_records++] = new_record;
}

void display_records() {
    for (int i = 0; i < num_records; i++) {
        printf("%s -> %s\n", database[i].key, database[i].value);
    }
}

void search_record(char *key) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Record found: %s -> %s\n", key, database[i].value);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    add_record("Name", "John");
    add_record("Age", "25");
    add_record("City", "New York");

    display_records();

    search_record("Age");

    return 0;
}
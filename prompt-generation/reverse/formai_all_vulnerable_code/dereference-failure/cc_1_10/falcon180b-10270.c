//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_RECORD_LENGTH 50

typedef struct {
    char *key;
    char *value;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record(char *key, char *value) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: database is full.\n");
        return;
    }
    records[num_records].key = strdup(key);
    records[num_records].value = strdup(value);
    num_records++;
}

void remove_record(char *key) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].key, key) == 0) {
            free(records[i].key);
            free(records[i].value);
            num_records--;
            memmove(&records[i], &records[i+1], (num_records-i)*sizeof(Record));
            return;
        }
    }
    printf("Error: record not found.\n");
}

void print_records() {
    int i;
    for (i = 0; i < num_records; i++) {
        printf("%s: %s\n", records[i].key, records[i].value);
    }
}

void search_records(char *key) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].key, key) == 0) {
            printf("%s: %s\n", records[i].key, records[i].value);
            return;
        }
    }
    printf("Error: record not found.\n");
}

int main() {
    add_record("name", "John");
    add_record("age", "30");
    print_records();
    search_records("name");
    remove_record("age");
    print_records();
    return 0;
}
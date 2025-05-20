//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

void read_records(Record* records, int num_records) {
    FILE* file = fopen("records.txt", "r");
    if (file == NULL) {
        printf("Error: could not open records file.\n");
        exit(1);
    }

    for (int i = 0; i < num_records; i++) {
        Record record;
        if (fscanf(file, "%s %s\n", record.key, record.value)!= 2) {
            printf("Error: malformed record in records file.\n");
            exit(1);
        }
        records[i] = record;
    }

    fclose(file);
}

void write_records(Record* records, int num_records) {
    FILE* file = fopen("records.txt", "w");
    if (file == NULL) {
        printf("Error: could not open records file.\n");
        exit(1);
    }

    for (int i = 0; i < num_records; i++) {
        fprintf(file, "%s %s\n", records[i].key, records[i].value);
    }

    fclose(file);
}

int main() {
    Record records[MAX_RECORDS];
    int num_records = 0;

    read_records(records, MAX_RECORDS);
    num_records = MAX_RECORDS;

    char key[MAX_KEY_SIZE];
    printf("Enter a key to search for: ");
    scanf("%s", key);

    Record* result = NULL;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].key, key) == 0) {
            result = &records[i];
            break;
        }
    }

    if (result == NULL) {
        printf("No record found with key '%s'.\n", key);
    } else {
        printf("Value for key '%s': %s\n", key, result->value);
    }

    return 0;
}
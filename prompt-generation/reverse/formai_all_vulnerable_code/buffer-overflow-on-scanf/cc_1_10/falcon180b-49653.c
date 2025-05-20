//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

// Data structure for storing records
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

// Function for comparing two keys
int compare_keys(const void* a, const void* b) {
    const char* key1 = *(const char**)a;
    const char* key2 = *(const char**)b;
    return strcmp(key1, key2);
}

// Function for printing a record
void print_record(const Record* record) {
    printf("Key: %s\nValue: %s\n", record->key, record->value);
}

// Function for loading records from a file
int load_records(const char* filename, Record* records, int max_records) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    int num_records = 0;
    while (fscanf(file, "%s %s\n", records[num_records].key, records[num_records].value)!= EOF) {
        num_records++;
        if (num_records >= max_records) {
            printf("Reached maximum number of records\n");
            break;
        }
    }

    fclose(file);
    return 0;
}

// Function for sorting records by key
void sort_records(Record* records, int num_records) {
    qsort(records, num_records, sizeof(Record), compare_keys);
}

// Function for searching a record by key
int search_record(const char* key, Record* records, int num_records) {
    Record record = {.key = key };
    int result = bsearch(&record, records, num_records, sizeof(Record), compare_keys);
    if (result!= NULL) {
        print_record(result);
        return 0;
    } else {
        printf("Record not found\n");
        return 1;
    }
}

int main() {
    Record records[100];
    int num_records = 0;

    // Load records from a file
    load_records("records.txt", records, 100);

    // Sort records by key
    sort_records(records, num_records);

    // Search for a record by key
    char search_key[MAX_KEY_LENGTH];
    printf("Enter a key to search for: ");
    scanf("%s", search_key);
    int search_result = search_record(search_key, records, num_records);

    // Print all records
    printf("\nAll records:\n");
    for (int i = 0; i < num_records; i++) {
        print_record(&records[i]);
    }

    return 0;
}